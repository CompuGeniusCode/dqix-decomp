import capstone, sys
data=open('extract/usa/arm9_overlays/ov027.bin','rb').read()
base=0x021d8a40
def dump(addr,n):
    off=addr-base
    md=capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM)
    for i in md.disasm(data[off:off+n],addr):
        print(f'{i.address:08x}: {i.mnemonic} {i.op_str}')
addr=int(sys.argv[1],16)
n=int(sys.argv[2],16)
dump(addr,n)
