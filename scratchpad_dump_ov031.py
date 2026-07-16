import sys
from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM

base = 0x02200160
path = "build/usa/build/arm9_ov031.bin"
with open(path, "rb") as f:
    data = f.read()

addr = int(sys.argv[1], 16)
count = int(sys.argv[2]) if len(sys.argv) > 2 else 80
off = addr - base
md = Cs(CS_ARCH_ARM, CS_MODE_ARM)
n = 0
for i in md.disasm(data[off:off+4*400], addr):
    print(f'{i.address:08x}: {i.mnemonic} {i.op_str}'.rstrip())
    n += 1
    if n >= count:
        break
