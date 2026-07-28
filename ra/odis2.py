import sys
from elftools.elf.elffile import ELFFile
from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM
f=open(sys.argv[1],'rb'); e=ELFFile(f)
names={}
st=e.get_section_by_name('.symtab')
for sym in st.iter_symbols():
    if sym['st_info']['type']=='STT_FUNC' and sym['st_size']:
        names.setdefault(sym['st_shndx'],[]).append(sym.name)
md=Cs(CS_ARCH_ARM,CS_MODE_ARM)
for i,s in enumerate(e.iter_sections()):
    if s.name=='.text':
        print("--- .text[%d] %s"%(i,names.get(i,'?')))
        for ins in md.disasm(s.data(),0): print("    %s %s"%(ins.mnemonic,ins.op_str))
