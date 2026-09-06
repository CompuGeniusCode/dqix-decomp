import re,subprocess,sys,os,glob
os.chdir(r"D:\Downloads\decomp\dqix-decomp")
SP=r"C:\Users\yzsco\AppData\Local\Temp\claude\D--Downloads-decomp\6fa45df1-49d4-464d-913a-1decd1e3de5d\scratchpad"
BR=('b','bl','beq','bne','bhi','bls','blt','bge','bgt','ble','bcs','bcc','bmi','bpl','blo','bhs')
def norm(lines):
    out=[]
    for l in lines:
        l=l.strip()
        if not l: continue
        l=re.sub(r'^0x[0-9a-f]+ ','',l)
        op=l.split()[0]
        if op in BR: l=re.sub(r'#0x[0-9a-f]+$','#T',l)
        if op.startswith('andeq') or op.startswith('andseq'): l='POOLWORD'
        out.append(re.sub(r'\s+',' ',l))
    return out
tgt=norm(open(sys.argv[2]).read().splitlines())
src=sys.argv[1]
for cc in sorted(glob.glob(r"tools\mwccarm\*\*\mwccarm.exe")):
    o="ra/_v.o"
    r=subprocess.run([cc,"-O2","-enum","int","-char","signed","-str","noreuse","-proc","arm946e","-gccext,on",
        "-fp","soft","-inline","noauto","-lang=c++","-Cpp_exceptions","off","-RTTI","off","-interworking",
        "-w","off","-sym","on","-gccinc","-nolink","-i","include","-d","usa","-c",src,"-o",o],capture_output=True,text=True)
    if r.returncode!=0:
        print("%-40s COMPILE-FAIL"%cc); continue
    d=subprocess.run([sys.executable,os.path.join(SP,"odis.py"),o],capture_output=True,text=True).stdout
    mine=norm(d.splitlines())
    n=max(len(tgt),len(mine)); bad=sum(1 for i in range(n) if (tgt[i] if i<len(tgt) else '-')!=(mine[i] if i<len(mine) else '-'))
    print("%-40s diffs=%d  len=%d/%d"%(cc,bad,len(mine),len(tgt)))
