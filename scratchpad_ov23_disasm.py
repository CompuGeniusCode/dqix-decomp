#!/usr/bin/env python3
import sys
from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM

BASE = 0x021D8A40  # ov023 ram base address
PATH = "extract/usa/arm9_overlays/ov023.bin"

def dump(addr, size):
    off = addr - BASE
    with open(PATH, 'rb') as f:
        f.seek(off)
        data = f.read(size)
    md = Cs(CS_ARCH_ARM, CS_MODE_ARM)
    for i in md.disasm(data, addr):
        print(f'{i.address:08x}: {i.mnemonic} {i.op_str}'.rstrip())

if __name__ == '__main__':
    addr = int(sys.argv[1], 16)
    size = int(sys.argv[2], 16) if len(sys.argv) > 2 else 0x80
    dump(addr, size)
