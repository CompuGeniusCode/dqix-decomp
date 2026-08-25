#!/usr/bin/env python3

"""Fails if a delinked object has code bytes that no symbol covers.

dsd emits no ARM mapping symbol ($a/$t/$d) for such a range, which leaves the object
undisassemblable: objdiff aborts on it, and the range is invisible to the decomp. It
happens when a code section in delinks.txt spans an address that symbols.txt never
declares, so the fix is always to declare the missing symbol.
"""

import argparse
import struct
import sys
from pathlib import Path

parser = argparse.ArgumentParser(description="Checks delinked objects for uncovered code")
parser.add_argument('objects_file', type=Path, help="Path to the object list from 'dsd lcf'")
parser.add_argument('-s', type=Path, dest='symbols_hint', required=False,
                    help="symbols.txt to name in the error message")
args = parser.parse_args()

SHT_SYMTAB = 2
CODE_SECTIONS = ('.text', '.init')


def sections(data: bytes):
    """Yields (name, index, type, offset, size, link, entsize) for an ELF32 LE object."""
    e_shoff, = struct.unpack_from('<I', data, 0x20)
    e_shentsize, e_shnum, e_shstrndx = struct.unpack_from('<HHH', data, 0x2e)
    headers = []
    for i in range(e_shnum):
        base = e_shoff + i * e_shentsize
        name_off, sh_type = struct.unpack_from('<II', data, base)
        sh_offset, sh_size, sh_link = struct.unpack_from('<III', data, base + 0x10)
        sh_entsize, = struct.unpack_from('<I', data, base + 0x24)
        headers.append((name_off, sh_type, sh_offset, sh_size, sh_link, sh_entsize))
    str_base = headers[e_shstrndx][2]
    for i, (name_off, sh_type, sh_offset, sh_size, sh_link, sh_entsize) in enumerate(headers):
        end = data.index(b'\0', str_base + name_off)
        name = data[str_base + name_off:end].decode('ascii', 'replace')
        yield name, i, sh_type, sh_offset, sh_size, sh_link, sh_entsize


def uncovered_code(path: Path):
    """Names of code sections holding bytes that only the section symbol covers."""
    data = path.read_bytes()
    if data[:4] != b'\x7fELF':
        return []
    secs = list(sections(data))
    covered = set()
    for name, _, sh_type, sh_offset, sh_size, sh_link, sh_entsize in secs:
        if sh_type != SHT_SYMTAB or not sh_entsize:
            continue
        str_base = secs[sh_link][3]
        for i in range(sh_size // sh_entsize):
            base = sh_offset + i * sh_entsize
            st_name, = struct.unpack_from('<I', data, base)
            st_shndx, = struct.unpack_from('<H', data, base + 0x0e)
            if not st_name:
                continue
            end = data.index(b'\0', str_base + st_name)
            sym = data[str_base + st_name:end].decode('ascii', 'replace')
            if sym not in CODE_SECTIONS:
                covered.add(st_shndx)
    return [
        name for name, i, _, _, sh_size, _, _ in secs
        if name in CODE_SECTIONS and sh_size and i not in covered
    ]


# Read the link list rather than globbing the delinks directory: renaming or removing a
# delinks.txt entry renumbers dsd's auto-generated units, and the objects it wrote under
# the old numbering stay on disk.
bad = []
for line in args.objects_file.read_text(encoding='utf-8').splitlines():
    object_file = Path(line.strip())
    if not line.strip() or not object_file.is_file():
        continue
    for section in uncovered_code(object_file):
        bad.append((object_file, section))

if bad:
    print(f"{len(bad)} delinked code section(s) have no symbol covering them:")
    for object_file, section in bad:
        print(f"  {object_file}  {section}")
    where = args.symbols_hint or "the module's symbols.txt"
    print(f"Declare a symbol for each range in {where}; dsd cannot emit an ARM mapping")
    print("symbol without one, which leaves those bytes undisassemblable.")
    sys.exit(1)
