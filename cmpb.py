import subprocess,os,io,sys,capstone
from elftools.elf.elffile import ELFFile
CC="./tools/mwccarm/2.0/sp1p5/mwccarm.exe"; BASE=0x021536e0
PR=open("extract/usa/arm9_overlays/ov004.bin","rb").read()
src=sys.argv[1]; addr=int(sys.argv[2],16); out="_cb.o"
r=subprocess.run([CC,"-O2","-enum","int","-char","signed","-str","noreuse","-proc","arm946e","-gccext,on","-fp","soft","-inline","noauto","-lang=c++","-Cpp_exceptions","off","-RTTI","off","-interworking","-w","off","-sym","on","-gccinc","-nolink","-msgstyle","gcc","-i","include",src,"-o",out],capture_output=True,text=True)
if not os.path.exists(out): print("COMPILE FAIL",r.stdout,r.stderr); sys.exit(1)
buf=open(out,"rb").read(); f=ELFFile(io.BytesIO(buf)); mine=f.get_section_by_name(".text").data(); os.remove(out)
def isbr(w): return ((w>>25)&7)==0b101 or (w>>25)==0b1111101
off=addr-BASE; orig=PR[off:off+len(mine)]; d=[]
md=capstone.Cs(capstone.CS_ARCH_ARM,capstone.CS_MODE_ARM)
for i in range(0,len(mine),4):
    mw=int.from_bytes(mine[i:i+4],'little'); ow=int.from_bytes(orig[i:i+4],'little')
    # skip pool reloc words (data symbol): if orig word is a plausible address >0x02000000 and mine=0
    if mw!=ow and not (isbr(mw) and isbr(ow)):
        if mw==0 and ow>0x02000000: continue
        d.append(i)
print(f"len={len(mine)} real-diffs={len(d)}","-> BYTE-EXACT" if not d else "")
for i in d[:8]:
    a=list(md.disasm(mine[i:i+4],0)); b=list(md.disasm(orig[i:i+4],0))
    print(f"  +{i:#x}: mine[{(a[0].mnemonic+' '+a[0].op_str) if a else '?':24}] orig[{(b[0].mnemonic+' '+b[0].op_str) if b else '?'}]")
