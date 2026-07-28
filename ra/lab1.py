import sys; sys.path.insert(0,'ra')
exec(open('ra/lab.py').read())
# vary: uses of a, uses of b, calls between defs
for na in (1,2,3):
  for nb in (1,2,3):
    body =  "    int a = f(1);\n"
    body += "    int b = f(2);\n"
    for i in range(max(na,nb)):
        ua = "a" if i<na else "0"
        ub = "b" if i<nb else "0"
        body += "    h(%s,%s);\n"%(ua,ub)
    body += "    return 0;"
    L=compile_body(body)
    txt="\n".join(l.strip() for l in L)
    # a is def'd from first bl, b from second
    movs=re.findall(r'mov (r\d+), r0',txt)
    print("na=%d nb=%d  defs=%s"%(na,nb,movs[:3]))
