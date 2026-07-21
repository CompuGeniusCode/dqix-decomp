import subprocess, os, io, sys, re
from elftools.elf.elffile import ELFFile

def main():
    ov = sys.argv[1]          # e.g. "031"
    addr = int(sys.argv[2], 16)
    src = sys.argv[3]
    ov_dir = f"config/usa/arm9/overlays/ov{ov}"
    delinks = open(f"{ov_dir}/delinks.txt").read()
    m = re.search(r"\.text\s+start:0x([0-9a-fA-F]+)", delinks)
    base = int(m.group(1), 16)
    pr_path = f"extract/usa/arm9_overlays/ov{ov}.bin"
    PR = open(pr_path, "rb").read()

    symbols = open(f"{ov_dir}/symbols.txt").read()
    sm = re.search(r"addr:0x0*%x\b" % addr, symbols)
    exp_size = None
    if sm:
        line_start = symbols.rfind("\n", 0, sm.start()) + 1
        line = symbols[line_start:symbols.find("\n", sm.start())]
        szm = re.search(r"size=0x([0-9a-fA-F]+)", line)
        if szm:
            exp_size = int(szm.group(1), 16)

    out = "_mygate_out.o"
    cc = "./tools/mwccarm/2.0/sp1p5/mwccarm.exe"
    cmd = [cc, "-O2", "-enum", "int", "-char", "signed", "-str", "noreuse",
           "-proc", "arm946e", "-gccext,on", "-fp", "soft", "-inline", "noauto",
           "-lang=c++", "-Cpp_exceptions", "off", "-RTTI", "off", "-interworking",
           "-w", "off", "-sym", "on", "-gccinc", "-nolink", "-msgstyle", "gcc",
           "-i", "include", "-d", "usa", src, "-o", out]
    r = subprocess.run(cmd, capture_output=True, text=True)
    if not os.path.exists(out):
        print("COMPILE FAIL")
        print(r.stdout)
        print(r.stderr)
        sys.exit(1)

    buf = open(out, "rb").read()
    f = ELFFile(io.BytesIO(buf))
    text_sec = f.get_section_by_name(".text")
    mine = text_sec.data()

    # count FUNC symbols defined in .text -> overgen check
    symtab = f.get_section_by_name(".symtab")
    func_syms = []
    if symtab is not None:
        for sym in symtab.iter_symbols():
            if sym["st_info"]["type"] == "STT_FUNC" and sym["st_shndx"] not in ("SHN_UNDEF",) and not sym.name.startswith("$"):
                func_syms.append((sym.name, sym["st_value"], sym["st_size"]))
    os.remove(out)

    if exp_size is not None and len(mine) != exp_size:
        print(f"SIZE/OVERGEN mine_len={len(mine):#x} exp_size={exp_size:#x} funcs={func_syms}")
        sys.exit(1)
    if len(func_syms) > 1:
        print(f"SIZE/OVERGEN multiple funcs in .text: {func_syms}")
        sys.exit(1)

    def isbr(w):
        return ((w >> 25) & 7) == 0b101 or (w >> 25) == 0b1111101

    off = addr - base
    orig = PR[off:off + len(mine)]
    diffs = []
    undef_syms = set()
    reloc_targets = {s.name: s for s in (f.get_section_by_name(".symtab").iter_symbols() if f.get_section_by_name(".symtab") else [])}
    for i in range(0, len(mine), 4):
        mw = int.from_bytes(mine[i:i+4], "little")
        ow = int.from_bytes(orig[i:i+4], "little")
        if mw == ow:
            continue
        if isbr(mw) and isbr(ow):
            continue
        if mw == 0 and ow > 0x02000000:
            continue
        diffs.append(i)

    if diffs:
        print(f"BYTEDIFF@{[hex(d) for d in diffs[:16]]} len={len(mine):#x}")
        sys.exit(1)

    print("MATCH")

if __name__ == "__main__":
    main()
