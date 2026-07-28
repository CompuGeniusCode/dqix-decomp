import re,subprocess,sys,os,itertools
os.chdir(r"D:\Downloads\decomp\dqix-decomp")
SP=r"C:\Users\yzsco\AppData\Local\Temp\claude\D--Downloads-decomp\6fa45df1-49d4-464d-913a-1decd1e3de5d\scratchpad"
CC=[r"tools\mwccarm\2.0\sp1p5\mwccarm.exe","-O2","-enum","int","-char","signed","-str","noreuse",
    "-proc","arm946e","-gccext,on","-fp","soft","-inline","noauto","-lang=c++","-Cpp_exceptions","off","-RTTI","off",
    "-interworking","-w","off","-sym","on","-gccinc","-nolink","-i","include","-d","usa"]
HDR='#include <globaldefs.h>\nextern "C" int f(int);\nextern "C" void sink(int);\n'
def run(body):
    open("ra/_l2.cpp","w").write(HDR+'extern "C" int tf(int* p) {\n%s\n    return 0;\n}\n'%body)
    r=subprocess.run(CC+["-c","ra/_l2.cpp","-o","ra/_l2.o"],capture_output=True,text=True)
    if r.returncode!=0: return None
    d=subprocess.run([sys.executable,os.path.join(SP,"odis.py"),"ra/_l2.o"],capture_output=True,text=True).stdout
    return [l.strip() for l in d.splitlines()]
def regs(lines,n):
    # collect 'mov r0, rX' immediately preceding a bl, in order; last n are the sinks
    out=[]
    for i,l in enumerate(lines):
        m=re.match(r'mov r0, (r\d+)$',l)
        if m and i+1<len(lines) and lines[i+1].startswith('bl'): out.append(m.group(1))
    return out[-n:]
for n in (2,3,4):
  for pat in itertools.product('CL',repeat=n):
    body=""
    for k,c in enumerate(pat):
        body += "    int v%d = %s;\n"%(k, ("f(%d)"%k) if c=='C' else ("p[%d]"%(k+1)))
    body += "    sink(0);\n"
    for k in range(n): body += "    sink(v%d);\n"%k
    L=run(body)
    print("%-6s %s" % ("".join(pat), regs(L,n) if L else "FAIL"))
