import re,subprocess,sys,os,itertools,random
os.chdir(r"D:\Downloads\decomp\dqix-decomp")
SP=r"C:\Users\yzsco\AppData\Local\Temp\claude\D--Downloads-decomp\6fa45df1-49d4-464d-913a-1decd1e3de5d\scratchpad"
CC=[r"tools\mwccarm\2.0\sp1p5\mwccarm.exe","-O2","-enum","int","-char","signed","-str","noreuse",
    "-proc","arm946e","-gccext,on","-fp","soft","-inline","noauto","-lang=c++","-Cpp_exceptions","off","-RTTI","off",
    "-interworking","-w","off","-sym","on","-gccinc","-nolink","-i","include","-d","usa"]
HDR='#include <globaldefs.h>\nextern "C" int f(int);\nextern "C" void sink(int);\nextern "C" int cond(int);\n'
def build(body):
    open("ra/_h.cpp","w").write(HDR+'extern "C" int th(int* p, int q) {\n%s\n}\n'%body)
    r=subprocess.run(CC+["-c","ra/_h.cpp","-o","ra/_h.o"],capture_output=True,text=True)
    if r.returncode!=0: return None
    return subprocess.run([sys.executable,os.path.join(SP,"odis.py"),"ra/_h.o"],capture_output=True,text=True).stdout
random.seed(7)
CALLDEF="int A = f(%d);"; COMPDEF="int B = p[%d] * 6;"
BLOCKS=[
 "    if (cond(%d)) { sink(%s); }\n",
 "    if (!cond(%d)) { sink(%s); f(%d); } else { sink(%s); }\n",
 "    if (cond(%d)) { f(7); sink(%s); } else { f(8); sink(%s); }\n",
 "    while (cond(%d)) { sink(%s); }\n",
 "    sink(%s);\n",
]
found=[]
tries=0
for trial in range(220):
    n=random.randint(2,5)
    body=""
    order=random.choice([0,1])
    if order==0: body += "    int A = f(1);\n    int B = p[3] * 6;\n"
    else:        body += "    int B = p[3] * 6;\n    int A = f(1);\n"
    if random.random()<0.5: body += "    if (A < 0) return 0;\n"
    for i in range(n):
        k=random.randrange(len(BLOCKS)); t=BLOCKS[k]
        vs=[random.choice(["A","B","A+B","B+A","A&0xff","q"]) for _ in range(t.count("%s"))]
        args=[]
        it=iter(vs)
        out=""
        # fill placeholders in order
        parts=re.split(r'(%d|%s)',t)
        for pp in parts:
            if pp=="%d": out+=str(random.randint(1,9))
            elif pp=="%s": out+=next(it)
            else: out+=pp
        body+=out
    body+="    sink(A); sink(B);\n    return 0;"
    d=build(body)
    if d is None: continue
    tries+=1
    L=[l.strip() for l in d.splitlines()]
    txt="\n".join(L)
    # A's def: 'mov rX, r0' right after first bl ; B's def: 'smulbb rY,'
    mA=re.search(r'bl [^\n]*\n\s*mov (r[0-9]+), r0',txt)
    mB=re.search(r'smulbb (r[0-9]+),',txt)
    if not mA or not mB: continue
    a,b=mA.group(1),mB.group(1)
    if not (a.startswith('r') and b.startswith('r')): continue
    ia,ib=int(a[1:]),int(b[1:])
    if ia<4 or ib<4: continue
    if ib<ia:
        found.append((a,b,body))
print("compiled=%d  INVERSIONS(computed below call)=%d"%(tries,len(found)))
if found:
    print(found[0][0],found[0][1]); print(found[0][2])
