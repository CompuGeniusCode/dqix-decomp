import re,subprocess,sys,os
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
def build(src):
    o=src[:-4]+'.o'
    r=subprocess.run([r"tools\mwccarm\2.0\sp1p5\mwccarm.exe","-O2","-enum","int","-char","signed","-str","noreuse",
        "-proc","arm946e","-gccext,on","-fp","soft","-inline","noauto","-lang=c++","-Cpp_exceptions","off","-RTTI","off",
        "-interworking","-w","off","-sym","on","-gccinc","-nolink","-i","include","-d","usa","-c",src,"-o",o],
        capture_output=True,text=True)
    if r.returncode!=0:
        print("COMPILE FAILED"); print(r.stdout+r.stderr); return None
    d=subprocess.run([sys.executable,os.path.join(SP,"odis.py"),o],capture_output=True,text=True)
    return d.stdout.splitlines()
tgt=norm(open(sys.argv[2]).read().splitlines())
ml=build(sys.argv[1])
if ml is None: sys.exit(1)
mine=norm(ml)
n=max(len(tgt),len(mine)); bad=0
for i in range(n):
    t=tgt[i] if i<len(tgt) else '---'
    m=mine[i] if i<len(mine) else '---'
    mark='   ' if t==m else '>>>'
    if t!=m: bad+=1
    print(f"{mark} {i*4:#06x}  {t:38s} | {m}")
print(f"DIFFS={bad}/{n}")
