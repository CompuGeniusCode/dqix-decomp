import capstone, re, sys
PRISTINE=open("extract/usa/arm9_overlays/ov023.bin","rb").read()
delinks=open("config/usa/arm9/overlays/ov023/delinks.txt").read()
STARTS=[int(m,16) for m in re.findall(r'start:0x([0-9a-f]+)', delinks)]
BASE=min(STARTS)
a=int(sys.argv[1],16)
slot=int(sys.argv[2],16)
orig=PRISTINE[a-BASE:a-BASE+slot]
md=capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM)
for insn in md.disasm(orig, 0):
    print(hex(insn.address), insn.mnemonic, insn.op_str)
