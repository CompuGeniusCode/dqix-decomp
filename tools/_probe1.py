import sys
sys.path.insert(0, "tools")
from _exp0200ae40 import run, base_text

b = base_text()
old = "    if (biased >= 0xffe00000u) {"
assert old in b
print("=== baseline ===")
print(run(b, show=1))
print("=== exp == 0x7ff ===")
print(run(b.replace(old, "    if (exp == 0x7ff) {"), show=12))
