import subprocess, os, sys
from elftools.elf.elffile import ELFFile
import capstone

REPO="D:/Downloads/decomp/dqix-decomp"
CC=f"{REPO}/tools/mwccarm/2.0/sp1p5/mwccarm.exe"
FLAGS="-O2 -enum int -char signed -str noreuse -proc arm946e -gccext,on -fp soft -inline noauto -lang=c++ -Cpp_exceptions off -RTTI off -interworking -w off -sym on -gccinc -nolink -i include -d usa".split()
SRC="src/Combat/Main/func_02096f80.cpp"
OBJ="/tmp_wg2.o"
os.chdir(REPO)

TARGET_BYTES = bytes.fromhex(
    "0130a0e3" "0110a047" "0210a0e2"
    "011000ec"  # placeholder, will be replaced by reading real ROM below
)

ADDR=0x02096f80
BASE=0x02000000
pristine = open("extract/usa/arm9/arm9.bin","rb").read()
target = pristine[ADDR-BASE:ADDR-BASE+0x30]

r=subprocess.run([CC]+FLAGS+["-c",SRC,"-o",OBJ],capture_output=True,text=True)
if r.returncode!=0:
    print("COMPILE FAIL"); print((r.stdout+r.stderr)[-800:]); sys.exit(1)
elf=ELFFile(open(OBJ,"rb"))
for s in elf.iter_sections():
    if s.name==".text":
        data=s.data()
print("size", hex(len(data)))
md=capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM)
print("--- MINE ---")
for i in md.disasm(data,0):
    print(hex(i.address), i.mnemonic, i.op_str)
print("--- TARGET ---")
for i in md.disasm(target,0):
    print(hex(i.address), i.mnemonic, i.op_str)
diffs=[i for i in range(min(len(data),len(target))) if data[i]!=target[i]]
print("byte diffs:", len(diffs), [hex(x) for x in diffs[:10]])
