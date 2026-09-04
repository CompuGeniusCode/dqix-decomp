# `func_02061c04` — work in progress, NOT matched

`c04.cpp` is a candidate for `main:02061c04` (10204 B / `0x27dc`, the largest function in arm9).
It is **27 bytes short of byte-exact** and must not be committed into `src/` until `wgate` says
`MATCH`. Nothing in this directory is built: `tools/configure.py` walks only `src/` and `libs/`.

It is archived here because it is a large hand-built artefact that otherwise exists only in a
scratchpad, and a scratchpad has been lost before.

The 27-byte source is eakeys' work, taken from decomp.me scratch `FUYhf`; it gates 27 here under
this project's own flags, not only under the scratch's.

## Gate it

    MWCC=2.0/sp2p2 python <scratchpad>/wgate.py main 02061c04 wip/02061c04/c04.cpp

**The compiler is not the project default.** This function only reaches its best on `2.0/sp2p2`;
on `sp1p5` it is thousands of bytes off. `wgate` honours `MWCC`; when this eventually lands in
`src/`, add the committed path to `tools/cc_overrides.txt` instead.

Note the directory names under `tools/mwccarm/` are NitroSDK versions, not compiler versions:
`2.0/sp1p5` is **mwcc 3.0 build 131**, `2.0/sp2p2` is **build 137** — the same `mwcc_30_137`
decomp.me offers. `dsi/*` are 4.0 builds 1018-1051.

## State

* the function is the right length, and every aligned case body has identical mnemonics (`shape=0`)
* the prologue is byte-exact and **all 62 stack slots are at the ROM's offsets** (`sp=0`)
* what remains is register NAMING in two case bodies:

| case | rows | residue |
|---|---|---|
| `0xe7` | 20 | `battle`/`rec` swapped: ROM `battle=r5 rec=r4`, ours the reverse |
| `0xd3` | 4 | address and loaded value swapped: ROM `add r1` / `ldr r2`, ours the reverse |

`python <scratchpad>/pad/caseresidue.py wip/02061c04/c04.cpp` prints those rows with their offsets.

## `c04_allregs.cpp` — the diagnostic, and the one question left

Same source with both register residues fixed. It gates **`reg=0`** — not one wrong register in
10204 bytes — but emits `0x27e0` against slot `0x27dc`, so it is four bytes too long and is NOT a
better candidate. It is here because it isolates the problem to a single question.

Both fixes are known:

* **0xe7** — reference `battle` a second time, either as `snap->a_lo = ((SrcWord44 *)(battle +
  0x7548))->v24` or as `snap = (SnapshotE7 *)(battle + 0x75d0)`. Either one flips the whole r4/r5
  pair. Both cost one `add`, because a battle-relative address in that body needs its own address
  computation while `rec + 0x44` is a free displacement.
* **0xd3** — mwcc couples the address peel to the register order and gives one or the other, never
  both. Let the compiler form the address (member chain, array member, union view, volatile field,
  named value) and you get `add r1, base, #0x2000` / `ldr r2, [r1, #0x38c]`: right registers, greedy
  peel. Form it in the source (cast of `char* + 0x1840`, pointer local, C++ reference,
  `(Cell*)p + 1`, inline helper) and you get `add r2, base, #0x1840` / `ldr r1, [r2, #0xb4c]`: the
  ROM's split, swapped registers. Measured over 21 source forms x 20 mwccarm builds.

**There is no slack to pay the four bytes with.** The bodies that look like wrong lengths (`0xa0`,
`0xe3`, `0xde`) differ only in literal-pool words attributed to the wrong body; every real
instruction matches. With `shape=0` on every aligned body, the instruction count equals the ROM's.

### The pointer round-trip is a third way to flip `0xe7`, at the same price

`char *battle = ...; battle++;` with every later use written `(battle - 1)` clears the `0xe7`
residue completely — `caseresidue` drops all 20 rows and the body reaches reg=0 — but the object is
`0x27e0`, the same four bytes over as `c04_allregs.cpp`. It is structurally different from the two
fixes above (no battle-relative address is formed anywhere), so the four bytes are the price of the
flip itself, not of the address computation. `battle--` / `(battle + 1)` and a struct-stride form
both land on `0x27e0` as well; round-tripping `rec` or `snap` instead is worse at `0x27e4`.

### Removing the file-wide pragma is a campaign, not an edit

`#pragma opt_propagation off` at line 1297 is not what the developers wrote, and the round-trip is
the rewrite that usually replaces it (see `worker_src/core.md`). Measured here: strip it and the
object is `0x27d0` — only 12 bytes short — but **1221 instructions differ**, mostly one recurring
shape where the ROM stages a constant in a register before a call (`ldrb r2,[r6,#0x332]` /
`mov r1,#1` / `mov r0,r6` / `str r1,[sp]`) and propagation sinks it to the use. The integer form of
the round-trip does not help: `v++` … `(v - 1)` folds at propagation time, so it emits byte-identical
code. Pointer arithmetic outlives the pass; integer arithmetic does not.

So the open question is exactly this: **what makes mwcc weight `battle` over `rec` without emitting
an instruction?** Everything free that was tried is inert — a CSE alias (`char *rec2 = battle +
0x7504;` used for one access, folded straight back into `rec`), `(void)battle;`, retyping `rec` as a
struct pointer so every use is a member access, `level` as short/ushort/uint/uncommitted/declared
later, and twelve pragmas (`opt_propagation`, `opt_common_subs`, `peephole`, `opt_dead_assignments`,
`opt_strength_reduction`, `opt_lifetimes`, `opt_unroll_loops`, `opt_vectorize_loops`,
`inline_max_size(0)`, `register_coloring`, `optimization_level 3` and `4`). Adding four bytes in a
*different* case does not flip it either, so the effect is local to `0xe7` rather than global
pressure.

## Where the real notes are

`OPEN_WORK.md` in the scratchpad holds the full account: every cracked idiom, every disproof, the
measured mwcc rules (stack layout ignores declaration order and scope; a frame that is the wrong
size is never a colouring problem; an address as one IR node lands in `r1` and as two nodes in
`r2`), and the tooling (`pad/caseresidue.py`, `pad/framemap.py`, `pad/casegrid.py`,
`pad/findshape.py`, `pad/probe_d3*.cpp`, `pad/hunt_d3.py`, `pad/hunt2.py`).
