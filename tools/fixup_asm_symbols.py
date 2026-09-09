"""Give an assembled object the symbol shape dsd's delinked objects have.

mwasmarm exports every `.global` as NOTYPE with size 0 and emits a `$d` mapping symbol for each
data run. dsd emits FUNC/OBJECT with real sizes and no `$d`, and objdiff aborts the entire report
-- "Failed to find right side symbol for paired left side symbol" -- when the two sides disagree.

Sizes come from the distance to the next exported symbol, and the type from the `$a`/`$t`/`$d`
mapping symbol covering the address.
"""
import struct
import sys

SHT_PROGBITS = 1
SHT_SYMTAB = 2
SHT_RELA = 4
SHT_REL = 9
SHF_EXECINSTR = 0x4
SYM_SIZE = 16
SHDR_FMT = "<IIIIIIIIII"
SYM_FMT = "<IIIBBH"
STT_OBJECT = 1
STT_FUNC = 2
MAPPING = (b"$a", b"$t", b"$d")


def _read(path):
    with open(path, "rb") as fh:
        return bytearray(fh.read())


def fixup(path):
    data = _read(path)
    if data[:4] != b"\x7fELF" or data[4] != 1 or data[5] != 1:
        raise SystemExit("%s: not a 32-bit little-endian ELF" % path)

    e_shoff, = struct.unpack_from("<I", data, 0x20)
    e_shentsize, e_shnum = struct.unpack_from("<HH", data, 0x2E)
    shdrs = [struct.unpack_from(SHDR_FMT, data, e_shoff + i * e_shentsize) for i in range(e_shnum)]

    symtabs = [i for i, sh in enumerate(shdrs) if sh[1] == SHT_SYMTAB]
    if not symtabs:
        return 0
    sym_index = symtabs[0]
    sym_off = e_shoff + sym_index * e_shentsize
    _, _, _, _, sh_offset, sh_size, sh_link, first_global, _, _ = shdrs[sym_index]
    str_offset = shdrs[sh_link][4]

    def name_of(st_name):
        if not st_name:
            return b""
        return bytes(data[str_offset + st_name:data.index(b"\0", str_offset + st_name)])

    entries = []
    for k in range(sh_size // SYM_SIZE):
        off = sh_offset + k * SYM_SIZE
        st_name, st_value, st_size, st_info, st_other, st_shndx = struct.unpack_from(SYM_FMT, data, off)
        entries.append([k, off, name_of(st_name), st_name, st_value, st_size, st_info, st_other, st_shndx])

    code_sections = {i for i, sh in enumerate(shdrs)
                     if sh[1] == SHT_PROGBITS and sh[2] & SHF_EXECINSTR}

    changed = 0
    for section in code_sections:
        marks = sorted((e[4], e[2]) for e in entries if e[8] == section and e[2] in MAPPING)
        exported = sorted((e[4], e) for e in entries
                          if e[8] == section and e[6] >> 4 == 1 and e[2] and e[2] not in MAPPING)
        end = shdrs[section][5]
        for pos, (value, entry) in enumerate(exported):
            following = exported[pos + 1][0] if pos + 1 < len(exported) else end
            size = following - value
            kind = STT_FUNC
            for addr, mark in marks:
                if addr <= value:
                    kind = STT_OBJECT if mark == b"$d" else STT_FUNC
            if entry[5] == size and entry[6] & 0xF == kind:
                continue
            entry[5], entry[6] = size, (entry[6] & 0xF0) | kind
            struct.pack_into(SYM_FMT, data, entry[1], entry[3], entry[4], entry[5],
                             entry[6], entry[7], entry[8])
            changed += 1

    keep, remap, dropped = [], {}, 0
    for e in entries:
        if e[2] == b"$d":
            dropped += 1
            continue
        remap[e[0]] = len(keep)
        keep.append(bytes(data[e[1]:e[1] + SYM_SIZE]))

    if dropped:
        for sh in shdrs:
            if sh[1] not in (SHT_REL, SHT_RELA) or sh[6] != sym_index:
                continue
            stride = 8 if sh[1] == SHT_REL else 12
            for r in range(sh[5] // stride):
                off = sh[4] + r * stride + 4
                r_info, = struct.unpack_from("<I", data, off)
                old = r_info >> 8
                if old not in remap:
                    raise SystemExit("%s: relocation references a dropped symbol" % path)
                struct.pack_into("<I", data, off, (remap[old] << 8) | (r_info & 0xFF))
        data[sh_offset:sh_offset + sh_size] = b"".join(keep) + b"\0" * (dropped * SYM_SIZE)
        struct.pack_into("<I", data, sym_off + 20, len(keep) * SYM_SIZE)
        struct.pack_into("<I", data, sym_off + 28, sum(1 for k in remap if k < first_global))

    if changed or dropped:
        with open(path, "wb") as fh:
            fh.write(data)
    return changed + dropped


if __name__ == "__main__":
    for arg in sys.argv[1:]:
        fixup(arg)
