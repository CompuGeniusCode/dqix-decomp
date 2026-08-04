import capstone
import re
PRISTINE=open("extract/usa/arm9_overlays/ov023.bin","rb").read()
delinks=open("config/usa/arm9/overlays/ov023/delinks.txt").read()
STARTS=[int(m,16) for m in re.findall(r'start:0x([0-9a-f]+)', delinks)]
BASE=min(STARTS)
a=0x021dd59c
slot=0x3d8
orig=PRISTINE[a-BASE:a-BASE+slot]
md=capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM)
for insn in md.disasm(orig, a):
    off = insn.address - a
    if 0x180 <= off <= 0x1c0 or 0x250 <= off <= 0x270:
        print(hex(off), hex(insn.address), insn.mnemonic, insn.op_str)
