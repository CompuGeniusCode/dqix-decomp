#!/bin/bash
# ra/run.sh <file.cpp> [...]  -> compile + disasm, terse
cd "D:/Downloads/decomp/dqix-decomp" || exit 1
for SRC in "$@"; do
  OUT="${SRC%.cpp}.o"
  tools/mwccarm/2.0/sp1p5/mwccarm.exe -O2 -enum int -char signed -str noreuse -proc arm946e \
    -gccext,on -fp soft -inline noauto -lang=c++ -Cpp_exceptions off -RTTI off -interworking \
    -w off -sym on -gccinc -nolink -i include -d usa -c "$SRC" -o "$OUT" > /tmp/ra_err.txt 2>&1
  if [ $? -ne 0 ]; then echo "### $SRC COMPILE FAILED"; cat /tmp/ra_err.txt; continue; fi
  echo "### $SRC"
  python "C:/Users/yzsco/AppData/Local/Temp/claude/D--Downloads-decomp/6fa45df1-49d4-464d-913a-1decd1e3de5d/scratchpad/odis.py" "$OUT"
done
