# src/Library — C standard library functions

These are matching decompilations of the game's bundled C runtime string/memory
routines (`memcpy`, `strlen`, `strncmp`, `strchr`, `strrchr`, `strcat`). Each one
compiles with `mwccarm` to **byte-identical** output versus the original ROM
(verified instruction-for-instruction).

## Status: matched but NOT yet in `delinks.txt`

They are intentionally **not** marked `complete` in `config/usa/arm9/delinks.txt`
yet, because they live below `0x0200f398` in the ARM9. Carving any function out of
that low region forces the auto-generated leftover object to contain the soft-float
division runtime (`_fdiv` / `_ddiv` / `_u32_div_f`), whose bodies embed constant-pool
`kind:data` labels. `mwldarm` then aborts with:

```
In section .text in file main_N.o, the sum of all symbol sizes exceed section size.
```

This is why the project currently has **no** `complete` files below `0x0200f398`.

## How to integrate them later

Once the low-region delinking is resolved (e.g. by also decompiling the float
runtime so no leftover object straddles it, or a `dsd` fix), add each file to
`config/usa/arm9/delinks.txt` with its range and rebuild:

```
src/Library/memcpy.cpp:   complete   .text start:0x02001a40 end:0x02001a60
src/Library/strlen.cpp:   complete   .text start:0x02003f0c end:0x02003f28
src/Library/strcat.cpp:   complete   .text start:0x02004040 end:0x02004070
src/Library/strncmp.cpp:  complete   .text start:0x02004184 end:0x020041b8
src/Library/strchr.cpp:   complete   .text start:0x020041b8 end:0x020041f4
src/Library/strrchr.cpp:  complete   .text start:0x020041f4 end:0x0200423c
```

The symbols (`memcpy`, `strlen`, …) are already present and correctly named in
`config/usa/arm9/symbols.txt`, so no symbol changes are needed.
