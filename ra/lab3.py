import re,subprocess,sys,os,itertools
exec(open('ra/lab2.py').read().split("for n in")[0])
def run2(body,extra=""):
    open("ra/_l3.cpp","w").write(HDR+extra+'extern "C" int tf(int* p, int c) {\n%s\n}\n'%body)
    r=subprocess.run(CC+["-c","ra/_l3.cpp","-o","ra/_l3.o"],capture_output=True,text=True)
    if r.returncode!=0: return None
    d=subprocess.run([sys.executable,os.path.join(SP,"odis.py"),"ra/_l3.o"],capture_output=True,text=True).stdout
    return [l.strip() for l in d.splitlines()]
def sinkregs(lines,n):
    out=[]
    for i,l in enumerate(lines):
        m=re.match(r'mov r0, (r\d+)$',l)
        if m and i+1<len(lines) and lines[i+1].startswith('bl'): out.append(m.group(1))
    return out[-n:]
print("== straight-line (control) ==")
for pat in ('CCL','CLC','LCC','CCC','LLL','CLL'):
    n=len(pat); body=""
    for k,ch in enumerate(pat): body+="    int v%d = %s;\n"%(k,("f(%d)"%k) if ch=='C' else "p[%d]"%(k+1))
    body+="    sink(0);\n"+"".join("    sink(v%d);\n"%k for k in range(n))+"    return 0;"
    print("%-5s %s"%(pat,sinkregs(run2(body),n)))
print("== uses split across a branch ==")
for pat in ('CCL','CLC','LCC','CCC','LLL','CLL'):
    n=len(pat); body=""
    for k,ch in enumerate(pat): body+="    int v%d = %s;\n"%(k,("f(%d)"%k) if ch=='C' else "p[%d]"%(k+1))
    body+="    if (c) {\n"+"".join("        sink(v%d);\n"%k for k in range(n))+"    } else {\n"
    body+="".join("        sink(v%d);\n"%k for k in range(n))+"    }\n    return 0;"
    L=run2(body); print("%-5s %s"%(pat,sinkregs(L,n)))
print("== defs in different blocks (d534 shape) ==")
for pat in ('CCL','CLC','CCC','CLL'):
    n=len(pat); body="    int v0 = %s;\n"%(("f(0)") if pat[0]=='C' else "p[1]")
    body+="    if (v0 < 0) return 0;\n"
    body+="    int v1 = %s;\n"%(("f(1)") if pat[1]=='C' else "p[2]")
    body+="    if (!f(9)) { sink(8); goto end; }\n    {\n"
    body+="    int v2 = %s;\n"%(("f(2)") if pat[2]=='C' else "p[3]")
    body+="".join("        sink(v%d);\n"%k for k in range(n))
    body+="    }\nend:\n    return 0;"
    L=run2(body); print("%-5s %s"%(pat,sinkregs(L,n)))
