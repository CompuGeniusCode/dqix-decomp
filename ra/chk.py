import re,subprocess,sys,os
os.chdir(r"D:\Downloads\decomp\dqix-decomp")
SP=r"C:\Users\yzsco\AppData\Local\Temp\claude\D--Downloads-decomp\6fa45df1-49d4-464d-913a-1decd1e3de5d\scratchpad"
CC=[r"tools\mwccarm\2.0\sp1p5\mwccarm.exe","-O2","-enum","int","-char","signed","-str","noreuse",
    "-proc","arm946e","-gccext,on","-fp","soft","-inline","noauto","-lang=c++","-Cpp_exceptions","off","-RTTI","off",
    "-interworking","-w","off","-sym","on","-gccinc","-nolink","-i","include","-d","usa"]
def go(src):
    o=src[:-4]+'.o'
    r=subprocess.run(CC+["-c",src,"-o",o],capture_output=True,text=True)
    if r.returncode!=0: return "COMPILE-FAIL: "+(r.stdout+r.stderr).strip().splitlines()[-1][:60]
    d=subprocess.run([sys.executable,os.path.join(SP,"odis.py"),o],capture_output=True,text=True).stdout
    t="\n".join(x.strip() for x in d.splitlines())
    c=re.search(r'movs (r\d+), r0',t); m=re.search(r'smulbb (r\d+),',t)
    n=len(t.splitlines())
    return "code=%s mult=%s  len=%d %s"%(c.group(1) if c else '?', m.group(1) if m else '?', n, 'SIZE!' if n!=79 else '')
for f in sys.argv[1:]: print("%-14s %s"%(f,go(f)))
