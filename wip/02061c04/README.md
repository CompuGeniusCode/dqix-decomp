# `func_02061c04` — work in progress, NOT matched

`c04.cpp` is a candidate for `main:02061c04` (10204 B / `0x27dc`, the largest function in arm9).
It is **36 bytes short of byte-exact** and must not be committed into `src/` until `wgate` says
`MATCH`. Nothing in this directory is built: `tools/configure.py` walks only `src/` and `libs/`.

It is archived here because it is a large hand-built artefact that otherwise exists only in the
scratchpad, and a scratchpad has been lost before.

## Gate it

    MWCC=2.0/sp2p2 python <scratchpad>/wgate.py main 02061c04 wip/02061c04/c04.cpp

**The compiler is not the project default.** This function only reaches 36 bytes on `2.0/sp2p2`
(equal on `sp2p3`/`sp2p4`); on `sp1p5` it is 3836 bytes off. All 24 mwccarm builds were gated: no
other reaches it. `wgate` honours `MWCC`; when this eventually lands in `src/`, add the committed
path to `tools/cc_overrides.txt` instead.

## State

* the function is the right length, all 134 case bodies are the right length
* the prologue is byte-exact (`push {r3,...}` / `sub sp,#0x220`)
* **all 62 stack slots are at the ROM's offsets** (`sp=0`)
* what remains is 36 bytes of register NAMING in three cases, with the instruction sequences already
  identical:

| case | bytes | residue |
|---|---|---|
| `0xe7` | 20 | `battle`/`rec` swapped: ROM `battle=r5 rec=r4`, ours the reverse |
| `0xe4` | 9 | pool pointer and loaded byte swapped over `{r1,r3}`; `r2` is already right |
| `0xd3` | 7 | address and loaded value swapped: ROM `add r1` / `ldr r2`, ours the reverse |

## Where the real notes are

`OPEN_WORK.md` in the scratchpad holds the full account: every cracked idiom, every disproof, the
measured mwcc rules (stack layout ignores declaration order and scope; callee-saved order flips
direction when a nested block contributes a long-lived value; an address as one IR node lands in
`r1` and as two nodes in `r2`; a call result colours differently from a parameter), and the tooling
(`pad/casegrid.py`, `pad/findshape.py`, `pad/findladder.py`, `pad/shapecat.py`, `pad/probe_morph*.cpp`).

Exhausted against these 36 bytes: 24 compiler builds, 29 flag sets, 40 pragmas, ~1000 source forms,
corpus mining for each shape, and morph bisection from known-good committed sources.
