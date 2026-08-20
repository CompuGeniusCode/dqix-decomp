import os, subprocess, sys

S = r"C:/Users/yzsco/AppData/Local/Temp/claude/D--Downloads-decomp/6fa45df1-49d4-464d-913a-1decd1e3de5d/scratchpad"
BASE = "src/Combat/Main/DoubleToFloat0200ae40.cpp"
TMP = "src/Combat/Main/_probe0200ae40.cpp"


def run(src_text, show=0, mwcc=None):
    open(TMP, "w", encoding="utf-8").write(src_text)
    env = dict(os.environ)
    if mwcc:
        env["MWCC"] = mwcc
    out = subprocess.run([sys.executable, S + "/wdiff.py", "main", "0200ae40", TMP],
                         capture_output=True, text=True, env=env).stdout.splitlines()
    if show:
        return "\n".join(out[:show])
    return out[0] if out else "??"


def base_text():
    return open(BASE, encoding="utf-8").read()
