import re,subprocess,sys,os,itertools
os.chdir(r"D:\Downloads\decomp\dqix-decomp")
SP=r"C:\Users\yzsco\AppData\Local\Temp\claude\D--Downloads-decomp\6fa45df1-49d4-464d-913a-1decd1e3de5d\scratchpad"
CC=[r"tools\mwccarm\2.0\sp1p5\mwccarm.exe","-O2","-enum","int","-char","signed","-str","noreuse",
    "-proc","arm946e","-gccext,on","-fp","soft","-inline","noauto","-lang=c++","-Cpp_exceptions","off","-RTTI","off",
    "-interworking","-w","off","-sym","on","-gccinc","-nolink","-i","include","-d","usa"]
HDR='#include <globaldefs.h>\nextern "C" int f(int);\nextern "C" void h(int,int);\nextern "C" void h1(int);\n'
def compile_body(body,name="tf"):
    src=HDR+'extern "C" int %s(int p) {\n%s\n}\n'%(name,body)
    open("ra/_lab.cpp","w").write(src)
    r=subprocess.run(CC+["-c","ra/_lab.cpp","-o","ra/_lab.o"],capture_output=True,text=True)
    if r.returncode!=0: return None
    return subprocess.run([sys.executable,os.path.join(SP,"odis.py"),"ra/_lab.o"],capture_output=True,text=True).stdout.splitlines()
def regof(lines,marker):
    # find 'mov rX, r0' after the bl following marker call arg
    return lines
def report(tag,body,pats):
    L=compile_body(body)
    if L is None: print(tag,"FAIL"); return
    txt="\n".join(l.strip() for l in L)
    out=[]
    for p in pats:
        m=re.search(p,txt)
        out.append(m.group(1) if m else "?")
    print("%-28s %s" % (tag, " ".join(out)))
    return txt
