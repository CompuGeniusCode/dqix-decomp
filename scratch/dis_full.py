import capstone, sys
from elftools.elf.elffile import ELFFile
elf=ELFFile(open(sys.argv[1],"rb"))
texts=[s for s in elf.iter_sections() if s.name=='.text']
data=texts[0].data()
md=capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM)
for insn in md.disasm(data, 0):
    print(hex(insn.address), insn.mnemonic, insn.op_str)
