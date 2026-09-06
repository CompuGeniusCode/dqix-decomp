#!/bin/bash
# dif.sh <src.cpp> <targetfile>  : compile, strip addrs, diff vs target
cd "D:/Downloads/decomp/dqix-decomp" || exit 1
bash ra/run.sh "$1" | grep -v '^###' | sed 's/#0x[0-9a-f]*/#L/g; s/^ *//' > /tmp/mine.txt
sed 's/^0x[0-9a-f]* //; s/#0x2[0-9a-f]\{6\}/#L/g; s/#0x[0-9a-f]\{1,3\}$/#L/g; s/^ *//' "$2" > /tmp/tgt.txt
diff -u /tmp/tgt.txt /tmp/mine.txt | head -80
