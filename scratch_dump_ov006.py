import sys
from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM
base=0x021536e0
data=open('build/usa/build/arm9_ov006.bin','rb').read()
def dump(addr,size):
    off=addr-base
    md=Cs(CS_ARCH_ARM, CS_MODE_ARM)
    chunk=data[off:off+size]
    for i in md.disasm(chunk, addr):
        print(f'{i.address:08x}: {i.mnemonic} {i.op_str}'.rstrip())

addrs = [
 (0x02153730,0xc),
 (0x02153b9c,0xc4),
 (0x02154138,0x134),
 (0x02155630,0xe0),
 (0x02158d8c,0x54),
 (0x02159c64,0x14c),
 (0x0215f4dc,0x264),
 (0x0215f7e8,0x200),
]
for a,s in addrs:
    print(f'=== func_ov006_{a:08x} ===')
    dump(a,s)
    print()
