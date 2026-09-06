import re,subprocess,sys,os,hashlib
os.chdir(r"D:\Downloads\decomp\dqix-decomp")
SP=r"C:\Users\yzsco\AppData\Local\Temp\claude\D--Downloads-decomp\6fa45df1-49d4-464d-913a-1decd1e3de5d\scratchpad"
CC=[r"tools\mwccarm\2.0\sp1p5\mwccarm.exe","-O2","-enum","int","-char","signed","-str","noreuse",
    "-proc","arm946e","-gccext,on","-fp","soft","-inline","noauto","-lang=c++","-Cpp_exceptions","off","-RTTI","off",
    "-interworking","-sym","on","-gccinc","-nolink","-i","include","-d","usa"]
def build(src,o,warn=False):
    args=CC+([] if warn else ["-w","off"])+["-c",src,"-o",o]
    r=subprocess.run(args,capture_output=True,text=True)
    return r.returncode, r.stdout+r.stderr
def dis(o):
    return subprocess.run([sys.executable,os.path.join(SP,"odis.py"),o],capture_output=True,text=True).stdout
base=open(sys.argv[1]).read()
opts=[l.strip() for l in open(sys.argv[2]) if l.strip()]
rc,out=build(sys.argv[1],"ra/_base.o")
bd=dis("ra/_base.o"); bh=hashlib.md5(bd.encode()).hexdigest()
print("BASE hash",bh[:8],len(bd.splitlines()),"lines")
for opt in opts:
    for val in ("on","off"):
        src="#pragma %s %s\n"%(opt,val)+base
        open("ra/_t.cpp","w").write(src)
        rc,msg=build("ra/_t.cpp","ra/_t.o",warn=True)
        if rc!=0: print("%-45s %-4s COMPILE-FAIL"%(opt,val)); continue
        bad = "illegal pragma" in msg or "unknown pragma" in msg or "not a valid" in msg
        d=dis("ra/_t.o"); h=hashlib.md5(d.encode()).hexdigest()
        tag = "SAME" if h==bh else "**DIFF**"
        note = " (unrecognized)" if bad else ""
        if not bad: print("%-45s %-4s %s%s"%(opt,val,tag,note))
