"""Run mwasmarm, then give the object dsd's symbol shape so objdiff can pair the two sides.

Ninja runs rule commands without a shell here, so the two steps cannot be joined with `&&`.

Usage: mwasm.py <assembler> [flags...] -o <object> <source>
"""
import subprocess
import sys

from fixup_asm_symbols import fixup

result = subprocess.run(sys.argv[1:])
if result.returncode:
    raise SystemExit(result.returncode)

fixup(sys.argv[sys.argv.index("-o") + 1])
