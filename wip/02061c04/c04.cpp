// SESSION 5 UPDATE: dense switch complete (all 134 case values now have a real
// `case` label; only 0x99, 0xc5, 0xe7 still route to `default: return 0;`).
// Filled ~30 more case bodies (0x7f,0x86-0x88,0x8f,0x90,0x94-0x97,0x9b,0xa1,0xb2,
// 0xd7-0xdf minus already-done,0xe0,0xe3-0xe6,0xe8,0xe9,0xcb,0xce). Size went
// 0x14c8 -> 0x2298 of 0x27dc (48% -> 63%). cb and ce (linked/table iteration
// loops) matched their EXACT target byte size (0xfc, 0xec) first try -- literal
// transliteration of loop shape + calls was sufficient, no register games needed.
//
// STILL default (real code, offsets from wlist.py, unchanged from before):
//   0x99 (+0x5cc) -- cross-jumps INTO case 0x6d's own body (mwcc tail-merge
//     between two different case clauses). Do not hand-write; find the exact
//     tail overlap first.
//   0xe7 (+0x2548, 0x21c=540 bytes) -- huge combat-record field-copy/bitpack
//     block (reads a "context" struct at battle+0x104+0x7400+0xcc into a
//     record, ~8 packed sub-fields via bic/orr, calls GetFieldPercentOver{307,
//     448,232,944}). Fully hand-decoded once already (see prior assistant
//     turn if transcript survives) but not yet written -- redo the decode from
//     wlist.py at that offset, it's mechanical bic/orr/str, just long.
//   0xc5 (+0x1ab0, 0x2e0=736 bytes) -- TRIED AND FAILED: two sequential range-
//     ladders (cmp/blt/cmp/ble chains) applied first to battle's current
//     "cbc" field then to msg->p1, covering value sets {0xd-0x26,0x28-0x71,
//     0x7b-0x92} (maybe +0x93, one dead trailing `cmp` never branches on --
//     unexplained). BOTH the match path and the exhaust-all-buckets path
//     converge to the SAME next instruction (verified via branch targets), so
//     the ladder has NO observable effect on control flow -- it must be doing
//     something with a side effect this session never found (or it's a
//     switch-with-empty-bodies whose bucketing algorithm this session's
//     C reproduction guessed wrong: writing the same case-value set as a real
//     `switch(cur){case 0xd: ... case 0x92: break; default: break;}` (twice,
//     once for `cur` once for `newVal`) only added 128 bytes total, not the
//     expected ~700 -- mwcc did NOT reproduce the ladder from that C shape.
//     Next idea untried: maybe it's not a switch at all but a `assert`/debug
//     macro left partially alive, or the ranges need to be individual
//     `if(v==K)` chains (not `case`) to block the bucketing optimization, or
//     the two ladders are actually testing DIFFERENT registers than assumed
//     and one of them DOES gate the final `if(cur!=newVal){memset+SetField}`
//     block -- re-verify the beq/bne graph with fresh eyes before retrying.
//     The `_Z13GetFieldAt0x0Pi`/`_Z24UpdatePlayClocks020ac4f8i` boolean-OR
//     prefix (first ~15 instructions of this case) IS believed correct
//     (`(v==5&&byte>1)||v==6`) and compiled clean; only the ladder is wrong.
//
// Frame/prologue and any register-only residues will NOT be meaningful until
// these three are filled in -- do not chase colorsweep on this file yet.

// SESSION 5 UPDATE: dense switch complete (all 134 case values now have a real
// `case` label; only 0x99, 0xc5, 0xe7 still route to `default: return 0;`).
// Filled ~30 more case bodies (0x7f,0x86-0x88,0x8f,0x90,0x94-0x97,0x9b,0xa1,0xb2,
// 0xd7-0xdf minus already-done,0xe0,0xe3-0xe6,0xe8,0xe9,0xcb,0xce). Size went
// 0x14c8 -> 0x2298 of 0x27dc (48% -> 63%). cb and ce (linked/table iteration
// loops) matched their EXACT target byte size (0xfc, 0xec) first try -- literal
// transliteration of loop shape + calls was sufficient, no register games needed.
//
// STILL default (real code, offsets from wlist.py, unchanged from before):
//   0x99 (+0x5cc) -- cross-jumps INTO case 0x6d's own body (mwcc tail-merge
//     between two different case clauses). Do not hand-write; find the exact
//     tail overlap first.
//   0xe7 (+0x2548, 0x21c=540 bytes) -- huge combat-record field-copy/bitpack
//     block (reads a "context" struct at battle+0x104+0x7400+0xcc into a
//     record, ~8 packed sub-fields via bic/orr, calls GetFieldPercentOver{307,
//     448,232,944}). Fully hand-decoded once already (see prior assistant
//     turn if transcript survives) but not yet written -- redo the decode from
//     wlist.py at that offset, it's mechanical bic/orr/str, just long.
//   0xc5 (+0x1ab0, 0x2e0=736 bytes) -- TRIED AND FAILED: two sequential range-
//     ladders (cmp/blt/cmp/ble chains) applied first to battle's current
//     "cbc" field then to msg->p1, covering value sets {0xd-0x26,0x28-0x71,
//     0x7b-0x92} (maybe +0x93, one dead trailing `cmp` never branches on --
//     unexplained). BOTH the match path and the exhaust-all-buckets path
//     converge to the SAME next instruction (verified via branch targets), so
//     the ladder has NO observable effect on control flow -- it must be doing
//     something with a side effect this session never found (or it's a
//     switch-with-empty-bodies whose bucketing algorithm this session's
//     C reproduction guessed wrong: writing the same case-value set as a real
//     `switch(cur){case 0xd: ... case 0x92: break; default: break;}` (twice,
//     once for `cur` once for `newVal`) only added 128 bytes total, not the
//     expected ~700 -- mwcc did NOT reproduce the ladder from that C shape.
//     Next idea untried: maybe it's not a switch at all but a `assert`/debug
//     macro left partially alive, or the ranges need to be individual
//     `if(v==K)` chains (not `case`) to block the bucketing optimization, or
//     the two ladders are actually testing DIFFERENT registers than assumed
//     and one of them DOES gate the final `if(cur!=newVal){memset+SetField}`
//     block -- re-verify the beq/bne graph with fresh eyes before retrying.
//     The `_Z13GetFieldAt0x0Pi`/`_Z24UpdatePlayClocks020ac4f8i` boolean-OR
//     prefix (first ~15 instructions of this case) IS believed correct
//     (`(v==5&&byte>1)||v==6`) and compiled clean; only the ladder is wrong.
//
// Frame/prologue and any register-only residues will NOT be meaningful until
// these three are filled in -- do not chase colorsweep on this file yet.

#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

// PARTIAL ATTEMPT — see notes at end of file before continuing this function.
// 2551-instr / 0x27dc-byte mega-switch (134 cases, msg->cmd in [0x64,0xe9]).
//
// SESSION 4 UPDATE (this session): started from the 0xac8-byte file left by session 3,
// added ~50 more case bodies (0x9c-0xa0,0xa2,0xa4-0xaf,0xb0,0xb1,0xb3-0xb9,0xba-0xc4,
// 0xc6-0xca,0xcc-0xd6), reaching 0x14c8/0x27dc bytes (BYTEDIFF 3064B/55 runs vs. 1770B/18
// runs at session start -- byte count goes UP as more of the target is materialized; track
// %complete via `total` in the SIZE/OVERGEN line, not BYTEDIFF, until the whole switch is
// filled in). Frame/prologue (push list, `sub sp,#0x220`) will NOT match until every case
// is real, because register pressure and stack layout are decided by the WHOLE function --
// do not chase the prologue diff, it is a symptom, not a target.
//
// CRITICAL BUG FOUND+FIXED THIS SESSION, watch for recurrence: the per-case offset table
// below uses DECIMAL idx labels ("98:0x1d90"). case_value = 0x64 + idx, and idx MUST be
// converted decimal->hex BEFORE the hex add (idx 98 -> 0x62 -> 0x64+0x62=0xC6). Adding the
// raw decimal digits to 0x64 (0x64+98 "=" 0xD2) is silently wrong and produces a case label
// that is off by a constant but still compiles clean (no duplicate-label error) because the
// TRUE case value at that slot is simply still sitting in the default: bucket. This happened
// for idx98-114 (case values 0xC6-0xD6) in an earlier draft this session and was caught only
// by manually re-deriving idx->hex for each one; it would NOT have been caught by compiling
// or by wdiff's early-instruction diff (dispatch-table divergence is expected until the whole
// switch is done). Re-verify every new case label against `0x64 + hex(idx)` before trusting it.
//
// UNVERIFIED GUESSES in this session's new cases (flag for next session, don't assume solid):
//   - 0xcd (+0x1f5c): local stream-reset buffer sized `char local[0x40]` -- the real size of
//     whatever ResetStruct020d3c08/InitAndMaybeStartStream020d3c28 operate on is unknown; if
//     this case's own bytes don't converge, try other sizes.
//   - 0xbf (+0x199c): the deck-shuffle draw-without-replacement loop's `memmove` 3rd arg is
//     literally `count-(idx+1)` with NO `*sizeof(short)` -- matches the disassembly's missing
//     shift, looked deliberately odd, kept as-is; don't "fix" it by adding a shift.
//   - 0xb0 (+0x1634): bitfield write `entry->flag17 = msg->p2` assumes a 17-bit lead field in
//     `BitFlag17Entry`; only the WRITE shape (lsl#31/lsr#14 idiom) is verified, not the layout.
//   - 0xcf (+0x2090): pooled word 0x02108844 treated as `&data_02108844` (address-of, per the
//     ".word data_YYYYYYYY" convention) even though the target null-checks it -- mwcc does not
//     appear to fold `&global != 0`, so the check compiles either way; not fully proven.
//
// STILL default: (real code untranslated) 0x6f,0x70,0x71 (true defaults, no body -- verified),
// 0x7f,0x86,0x87,0x88,0x8f,0x90,0x94,0x95,0x96,0x97,0x98(true default),0x99,0x9a(true default),
// 0x9b,0xa1,0xa3(true default),0xb2,0xc5,0xcb,0xce,0xd7,0xda,0xdb,0xdc,0xdd,0xde,0xdf,0xe0,0xe3-
// 0xe9. Use the per-idx offset table further down (still accurate, re-verified this session)
// plus `0x64 + hex(idx)` to find each one's body in wlist.py output. 0xc5 (+0x1ab0) is a ~700-
// byte range-classification ladder (two long chains of sequential cmp/blt/ble against literal
// thresholds, one for a battle-field value, one for msg->p1) -- large, tedious, but mechanical;
// budget a dedicated pass for it. 0xcb (+0x1e50) and 0xce (+0x1fa4) are both combatant-iteration
// loops with several nested branches -- read carefully before writing, do not guess the exit
// conditions.
//
// THIS SESSION'S KEY FINDING (read before touching anything else): the switch's DISPATCH
// itself was wrong, not just missing case bodies. wdiff on the inherited file showed the
// PROLOGUE/dispatch diverging from instruction #1 (push list, stack frame, the range
// compare). Root cause: the inherited C only declared explicit `case` labels for the
// ~30 values it had bodies for, so mwcc built a SMALL dense table (cmp r3,#0x26, covering
// 0x64-0x8a) plus separate bgt/bge/cmp checks for stray far labels (0x89,0xe1,0xe2).
// The TARGET instead does ONE `cmp r3,#0x85; addls pc,pc,r3,lsl#2` covering the FULL
// 0x64-0xe9 range (134 dense slots) -- which only happens if EVERY value in that range is
// an explicit case label (falling to `default:` is fine, but the label must exist).
// Fix applied below: every one of the 134 values is now a case label; unimplemented ones
// are attached to `default:` as a placeholder (`return 0`) so the table stays dense while
// their real bodies get filled in by later sessions. This does NOT make the function
// byte-exact by itself (case body SIZES still have to match for the table VALUES/addresses
// and the prologue's push-list/frame-size to line up -- those depend on total register/
// stack usage across the WHOLE function) but it is a real structural fix and the next
// session should build on it, not revert to sparse case lists.
//
// SECOND FINDING: identical-looking bodies are not automatically merged by the compiler
// unless the SOURCE groups them via C fallthrough (`case A: case B: ... body`). Only TWO
// real duplicate-body groups exist in this whole function (verified against wlist.py):
//   - case 0x79, 0x89, 0xe1  -> share one `AppendNodeToListField30(obj,msg,param3); return 1;`
//   - case 0x85, 0x8a, 0xe2  -> share a byte-identical second copy of the same 3-instr body
// 0x74,0x75,0x76,0x77,0x78,0x7a,0x7b,0x7c each have their OWN separate copy of that same
// 3-instruction call (verified: each is at a DIFFERENT offset in the target), even though
// the code is textually identical -- so each needs its OWN `case` clause, not a shared one.
// The inherited file merged all of these into one clause; that was the dispatch-shape bug.
//
// THIRD FINDING: some cases likely share function-level locals living on the (large, 0x220-
// byte) stack frame across DIFFERENT case bodies -- e.g. case 0x7f (+0x840) reads
// `[sp,#0x30]` as a pre-existing value before it ever writes it in that case, and case 0x84
// (+0xa40) writes `[sp,#0x2e]` but never reads it within its own body. Neither of these is
// resolved; do not guess a `case 0x7f` body without first checking whether `sp+0x30` is
// initialized by a DIFFERENT case or by code before the switch.
//
// idx -> body-offset (from func start); dup targets share one body. Table re-verified
// against wlist.py this session (previous session's copy was correct):
// 0:0x240 1:0x290 2:0x2e0 3:0x33c 4:0x398 5:0x3f4 6:0x450 7:0x48c 8:0x4c4 9:0x548
// 10:0x674 11:default 12:default 13:default 14:0x6c0 15:0x6d4 16:0x6e8 17:0x6f4
// 18:0x700 19:0x70c 20:0x718 21:0x724 22:0x730 23:0x73c 24:0x748 25:0x754
// 26:0x7d0 27:0x840 28:0x8cc 29:0x8d8 30:0x8ec 31:0x978 32:0xa40 33:0xab8
// 34:0xac4 35:0xc34 36:0xda0 37:0x724(=21) 38:0xab8(=33) 39:0xe1c 40:0xe48
// 41:0xe70 42:0xe7c 43:0xe90 44:0x1064 45:0x10e8 46:0x10f4 47:0x1114 48:0x1134
// 49:0x117c 50:0x11f8 51:0x1274 52:default 53:0x5cc 54:default 55:0x12a8
// 56:0x12dc 57:0x1310 58:0x138c 59:0x13b0 60:0x13d4 61:0x1418 62:0x1490
// 63:default 64:0x1538 65:0x154c 66:0x156c 67:0x158c 68:0x15bc 69:0x15c4
// 70:0x15e0 71:0x15f4 72:0x15fc 73:0x1604 74:0x160c 75:0x1614 76:0x1634
// 77:0x1668 78:0x16b8 79:0x170c 80:0x1798 81:0x17fc 82:0x1804 83:0x180c
// 84:0x1814 85:0x1840 86:0x1854 87:0x186c 88:0x1880 89:0x1900 90:0x1950
// 91:0x199c 92:0x14c0 93:0x1a44 94:0x1a80 95:0x1a9c 96:0x1aa8 97:0x1ab0
// 98:0x1d90 99:0x1df8 100:0x1e0c 101:0x1e14 102:0x1e30 103:0x1e50 104:0x1f4c
// 105:0x1f5c 106:0x1fa4 107:0x2090 108:0x20e0 109:0x2120 110:0x2188 111:0x21a0
// 112:0x21c4 113:0x21d0 114:0x223c 115:0x227c 116:0x22a8 117:0x230c 118:0x2338
// 119:0x2348 120:0x23c4 121:0x23d8 122:0x23ec 123:0x2434 124:0x2450 125:0x724(=21)
// 126:0xab8(=33) 127:0x246c 128:0x247c 129:0x24ac 130:0x2528 131:0x2548
// 132:0x2764 133:0x27b0
//
// NOTE idx53 (case 0x99) points at +0x5cc, which is INSIDE case 0x6d's own body (its
// second internal loop). That is very likely mwcc cross-jump / identical-tail folding
// between two textually-different case clauses whose tail happens to be byte-identical --
// not something to hand-write by guessing; flagged for the next session, not attempted.
//
// STATUS this session: rebuilt the switch to cover the FULL 134-value range as explicit
// case labels (dispatch-shape fix, see above). Added real bodies for 0x6c, 0x6d (bitfield
// set via `FlagsField0x2e`, list-walk over GetPointerFromArray0x3c(p0+0x6c,2)), split the
// wrongly-merged 0x74-0x7c group into individual clauses plus the two real dup groups,
// added 0x7e, 0x84, 0x8b, 0x8c, 0x8d, 0x8e (all read directly off wlist.py, cross-checked
// against redecode.py for the ones past the old capstone-death point -- wlist.py did NOT
// die this session, it produced the complete 2552-line listing in one call; the old
// "capstone dies at +0x1414" note in a prior session no longer applies, use wlist.py first).
// Kept 0x64-0x6b, 0x6e, 0x72/0x73, 0x7d, 0x80-0x83 as inherited (structure verified sound).
// Also added 0x91,0x92,0x93 (idx45-47, simple AppendNodeToListField30 / SetOrClearBitInArray
// with `msg->p1+0x776` as the index -- 0x776 is the compiler's canon split of a >0xff
// constant, confirmed via `add r2,r2,#0x76; add r2,r2,#0x700`).
//
// NOT attempted / still placeholder (`return 0` via default), each confirmed real code with
// its offset sitting right there in the table above for the next session:
//   0x7f (+0x840) -- six-value bitfield pack (7/7/3/5/5/6-ish widths via bic/orr chains
//     into RegisterSlotA/RegisterSlotB), blocked on the `[sp,#0x30]` cross-case local.
//   0x86,0x87,0x88 (+0x1854..0xe1c region, idx34-36) -- long bodies (0x170-0x16c bytes each).
//   0x8f (+0xe90) -- read but SKIPPED, has a loop over `GetGlobal02109418()+4` in steps of
//     0x10 whose bottom test is `cmp r3,#0` -- comparing the WALKING POINTER itself to zero,
//     not an obvious count/sentinel; do not guess, read it again with fresh eyes first.
//   0x94 (+0x1134) -- caches 3 fields off GetBattleStruct() into locals (like 0x84) that are
//     NEVER read again inside the case body (same dead-store-looking pattern as 0x84's
//     `s2e`) -- the read for BOTH cases is missing; go find what consumes it before writing
//     these as plain locals, or the store may get DCE'd and mismatch.
//   0x95,0x96 (+0x117c,+0x11f8) -- a matched flag=0/flag=1 pair, each: guard on
//     `func_02012fe4()!=0`, `FindEntryByKeys02019508(p0,p1,p2)`, then TWO `func_0206ea8c`
//     calls (args `obj,(uchar)p1,(short)(p2+0x80 or p2),flag`), THEN a THIRD call
//     `SetFlag0x40AndToggle0x4(?,p1,flag)` whose first argument (r0) is NOT reloaded before
//     the call -- it is whatever `func_0206ea8c` returned, not `obj`. Need func_0206ea8c's
//     return-value meaning before this can be written correctly; do not assume `obj`.
//   0x97 belongs to 0x96's tail, not a separate short case -- re-verify the idx51 offset
//     (0x1274) against a fresh read; my split was wrong once already this session.
//   0x9b (+0x12a8) -- func_ov017_0218b5b0()+0x3000, node=[+0xb60], list=[+0x6fc],
//     InitObj021bdbf0(node), node->0x11=(byte)msg->p1, PrependNodeToHead(list,node);
//     looked clean but not compiled/verified, treat as a strong lead not a fact.
//   everything idx52+ (case 0x98 on, +0x1274/0x1490 on) -- not read this session.
// Use wlist.py (whole-function listing, one call, no redecode.py needed anymore) and this
// header's offset table to keep going in ascending case-value order -- that order is what
// keeps the jump-table slots landing at the addresses this table already gives you.

extern "C" void SetOrClearBitInArray(void *obj, unsigned char *arr, int idx, int flag);
extern "C" void *func_0202ae18(void);
extern "C" int CheckField0NonZero(void *ctx);
extern "C" int GetSearchStructCurrentArrEntry(void *ctx);
extern "C" void func_ov017_021d0924(int a, int b, int p1, int flag);
extern "C" void ClearNibble0206ece8(int a, int b, unsigned char *c, unsigned d);
extern "C" void *func_ov017_0218b5b0(void);
extern "C" int func_0202c508(void *ctx);
extern "C" void *func_02012fe4(void);
extern "C" void *GetPointerFromArray0x3c(unsigned char *arr, unsigned idx);
extern "C" void AppendNodeToListField30(void *a, void *msg, void *list);
extern "C" void *_Z15GetBattleStructv();
extern "C" void SelectTableValueAndDispatch(void *battle, int p1);
extern "C" void *GetData02107930();
extern "C" int GetAccumulatedValue(void *battle);
extern "C" int GetSelectedTableIndex(void *battle);
extern "C" void EnqueueEventTag147_021cdaa0();
extern "C" void *GetGlobal02109418(void);
extern "C" int func_020961b0(void *g, int p1);
extern "C" int TestBitInByteArray(void *obj, unsigned char *arr, int idx);
extern "C" void Init020d9ae8(void *node, int mode);
extern "C" void AppendNodeToTail(void *list, void *node);
extern "C" void func_0206e164(void *obj, int p1, int mode);
extern "C" void *FindEntryById02096134(void *table, int p1);
extern "C" void SetBitWithOffset0206eb64(void *obj, int p2, int flag);
extern "C" void func_02018300(void *p0, void *node, int a, int b, int c);
extern "C" void func_ov017_021c1a98(void *ctx, int flag);
extern "C" void *_Z21GetCombatantUncheckedP12BattleStructi(void *battle, int idx);
extern "C" void _Z18SetBitInArray0x8ecPhi(void *arr, int idx);
extern "C" void _Z18SetBitInArray0x910Phi(void *arr, int idx);
extern "C" void _Z27ToggleElemKey2FlagInMap2010i(int key);
extern "C" void _Z35SetElemFlag8IfOverlayActive020ae730i(int key);
extern "C" void _Z29SetElemFlag0x4PairAndNotify17i(int key);
extern "C" void _Z29SetElemFlag0x4QuadAndNotify17i(int key);
extern "C" void _Z13SetActiveFlagP12BattleStructi(void *battle, int flag);
extern "C" void _Z31EnqueueEventTag23Field_021d0d58v();
extern "C" int _Z14ListContainsIdP16ListHead02046b60i(void *list, int id);
extern "C" void *func_ov017_021b8478(void *node);
extern "C" int _Z21IsField0xcNonNegativePi(void *p);
extern "C" void _Z20InitState60_021aa16cP11Obj021aa16c(void *node);
extern "C" void _Z17PrependNodeToHeadP16HeadList020469f8P16HeadNode020469f8(void *list, void *node);
extern "C" void _Z18Something_021a6b9cih(void *base, int flag);
extern "C" void *_Z27GetStatFieldPointer02064904Pvij(void *obj, int p1, int p2);
extern "C" void func_ov017_021a5568(void *node);
extern "C" void _Z26SetBytesAt20And21_021a55a4Phhh(void *node, int a, int b);
extern "C" void *_Z11GetBTRandomv();
extern "C" int _Z17NextRandomBetweenP6Randomii(void *rng, int lo, int hi);
extern "C" int _Z13NextRandomMaxP6Randomi(void *rng, int max);
extern short data_020e7de8[14];
extern "C" void *memmove(void *dst, const void *src, unsigned int n);
extern "C" void _Z27EnqueueEventTag142_021cd6d8P11Src021cd6d8(void *ev);
struct Src021cd6d8 {
    short f0, f1, f2, f3;
    unsigned char f4;
    short f5;
    signed char f6;
    int f7;
};
extern "C" void *_Z18GetField0x3b0ValueP12BattleStruct(void *battle);
extern "C" void _Z33StoreFields0x1e4And0x1e8IfNonZeroPhii(void *rec, int a, int b);
extern "C" void _Z17SetFlag0x4At0x168Ph(void *rec);
extern "C" void _Z23ClearTwoWordsAndFlag0x4P21FlagsAndWords0202ea20(void *rec);
extern "C" void *_Z15GetData02108f0cv();
extern "C" void func_0202c288(void);
extern "C" void _Z29ResetFieldsToDefault_021b994cP12Obj_021b994c(void *rec);
extern "C" void _Z27EnqueueEventTag153_021d079chht(int a, int b, int c);
extern "C" void _Z36NotifyElemAndOverlay17OnFlag020ae990i(int key);
extern "C" void func_020aea40(int a, int b);
extern "C" void func_ov017_02191484(void *base);
extern "C" void _Z19ResetStruct020d3c08Pc(void *local);
extern "C" void _Z31InitAndMaybeStartStream020d3c28P11Obj020d3c28(void *local);
extern "C" void *_Z29GetElementCount0xb4Stride0x24Phi(void *local, int idx);
extern "C" void func_ov017_021913d0(void *base, int field);
struct ElemFlags3Bit0d3d78 { unsigned char field3 : 3; unsigned char rest : 5; };
extern int data_02108844;
extern "C" void _Z28ResetFieldGroup4444_0218b664Pc(void *base);
extern "C" void _Z27EnqueueEventTag154_021d0860hhh(int a, int b, int c);
extern "C" void _Z30SetFieldFromHelper491_02198f70Pvh(void *base, int b);
extern "C" void func_ov017_0219c520(void);
extern "C" void _Z25SetName56AndFlag_0218d7b0PhPc(void *base, void *local);
struct BitFlag17Entry { unsigned int pad : 17; unsigned int flag17 : 1; };

extern "C" int _Z20GetPackedNibbleFieldP25PackedNibbleArray0206e120i(void *arr, int idx);
extern "C" void _Z12Init020d9decP14Struct020d9deci(void *node, int mode);
extern "C" void _Z18SetFlagBit020d9fb4P9S020d9fb4i(void *node, int flag);
extern "C" void *_Z17GetPtrField0x2a04P12BattleStruct(void *battle);
extern "C" int _Z17GetField5cb0ValuePc(void *p);
extern "C" int _Z17GetField5cb4ValuePc(void *p);
extern "C" int _Z17GetField5cb8ValuePc(void *p);
extern "C" void _Z20ClearRegions0206e080Pci(void *obj, int slot);
extern "C" void _Z31ClearIndexedEntryFields0206e0d0Pci(void *obj, int slot);
extern "C" void _Z24SetKeyedArrayBit0206e348Phii(void *obj, int p1, int flag);

// 0x1c bytes, not 0xc: the five cases that build one on the stack put the next local 0x1c higher.
struct CmdMsg64 { unsigned short cmd, p1, p2, p3, p4, p5; unsigned short rest[8]; };

// mwcc bitfield-write shape at node+0x2e: low nibble preserved, high 12 bits read-modify-
// written as a WIDE value (`flagsHi |= K`), not a single-bit set/clear.
struct FlagsField0x2e { unsigned short pad0x2e_lo : 4; unsigned short flagsHi : 12; };

extern "C" void func_020732cc(int p1);
extern "C" void _Z40SetHalfFieldsAndEnqueueIfActive_021d1c2ctt(unsigned short a, unsigned short b);
// First parameter is passed as an UNSIGNED short: the target converts with lsl #16 / lsr #16 and
// stops there. Declaring it `short` adds a second sign-extending pair at every call site.
extern "C" void _Z26EnqueueEventTagB5_021d1dc0ssPisi(unsigned short a, short b, int *c, short d, int e);
extern AllocatorUnion data_02114e20;
extern "C" void *AllocateAligned4(AllocatorUnion *alloc, unsigned int size);
extern "C" void TailForward02012da4(AllocatorUnion *alloc, void *data);
extern "C" void *func_02086f24(void *p, unsigned char b, SafeAllocator *alloc);
extern "C" void func_020aee04(unsigned short a, unsigned char b);
extern char data_02109bf4;
extern "C" void _Z27InitAndAppendEntity020dac40P12Root020dac40(void);
extern "C" void *_Z25GetCombatantWithFlag0x100P12BattleStructi(void *battle, int idx);
extern "C" void *_Z15GetFieldAt0x150Ph(void *p);
extern "C" void _Z27RemoveSlotShiftDown0208386cP13Slots0208386ci(void *slots, int idx);
extern "C" void _Z25DecrementKeyValue020a0a08P14KeyMap020a0a08ii(void *map, int key, int amount);
extern "C" void _Z21SyncEightElementFlagsv(void);
extern "C" void _Z21RegisterSlotA020cf0fci(int p);
extern "C" void _Z21RegisterSlotB020cf1a8i(int p);
extern "C" void _Z23ApplySlotConfig02095cfcii(void *g, int idx);
extern "C" int func_0202c540(void *ctx);
extern "C" void *_Z24GetCombatantAtField0x3acP12BattleStruct(void *battle);
extern "C" void _Z24CopyOutBattleField0x7ac0Pv(void *dst);
extern "C" void _Z23CopyHalfwordAndTwoBytesP19SmallRecord020643e0S0_(void *dst, void *src);
extern "C" int _Z22GetFieldPercentOver307P7S_a0870(void *p);
extern "C" int _Z22GetFieldPercentOver448P7S_a090c(void *p);
extern "C" int _Z22GetFieldPercentOver232P7S_a08a4(void *p);
extern "C" int _Z22GetFieldPercentOver944P7S_a08d8(void *p);

// case 0xe7 packs a battle snapshot at battle+0x104+0x7400+0xcc. Every mask in the target is
// exactly what a bitfield read/write emits, so the layout is modelled, not open-coded.
struct SnapshotE7 {
    unsigned char head[8];
    unsigned int a_lo : 17;
    unsigned int a_mid : 7;
    unsigned int a_hi : 7;
    unsigned int a_top : 1;
    unsigned int b_lo : 17;
    unsigned int b_mid : 7;
    unsigned int b_hi : 7;
    unsigned int b_top : 1;
    unsigned int c_lo : 9;
    unsigned int c_mid : 14;
    unsigned int c_top : 9;
    unsigned int d_lo : 8;
    unsigned int d_mid : 14;
    unsigned int d_hi : 10;
    unsigned int e_lo : 24;
    unsigned int done : 1;
    unsigned int e_top : 7;
    unsigned int total;
};
struct SrcWord44 { unsigned int v24 : 24; unsigned int hi8 : 8; };
struct SrcWord48 { unsigned int lo : 14; unsigned int v14 : 14; unsigned int hi : 4; };
struct SrcWord4c { unsigned int v9 : 9; unsigned int v14 : 14; unsigned int hi : 9; };
extern "C" void *_Z20GetGlobalPtr021075f4v(void);
extern "C" void *_Z29FindEntryPointerByKey0203df78Pvi(void *g, int key);
extern "C" void *_Z19GetField0xc02040538P9S02040538(void *entry);
extern "C" void _Z21RegisterSlotA020cf0fci(int p);
extern "C" int func_020ac2d4(int a, void *p1, void *p2, int flag);
extern "C" void func_020ac104(void *pooled, void *p1, int flag);
extern char data_0211e33c;
extern "C" void *_Z15InitObj021bdbf0Ph(void *node);
extern "C" void *_Z15InitObj021beba4Pc(void *node);
extern "C" void *_Z23FindEntryByKeys02019508P12Base02019508ii(void *base, int a, int b);
extern "C" void func_0206ea8c(void *obj, unsigned char a, short b, int flag);
extern "C" void _Z23SetFlag0x40AndToggle0x4P14Struct02013380ii(void *rec, int a, int b);
extern "C" void _Z19InitContext020e1154Pv(void *p);
extern "C" void func_ov017_021a9bc4(void *node, unsigned char b);
extern "C" void func_ov017_021a9a9c(void *node, unsigned char a, unsigned char b, unsigned short c, unsigned char d);
extern "C" void func_ov017_021a8614(void *base, short p1, unsigned short p2, unsigned short p3, unsigned short p4, unsigned short p5);
extern "C" void _Z27EnqueueEventTag141_021ce110itth(int a, unsigned short b, unsigned short c, unsigned char d);
extern "C" void func_0206e748(void *obj, int a, int b, int c, int d);
extern "C" void _Z20AppendNodeToField494P8Obj64af8P9Node64af8(void *obj, void *node);
extern "C" int _Z24CheckField0x56bLowNibbleP11Obj02061bd8(void *obj);
extern "C" void _Z21ClearFieldBit02053fe4P9T02053fe4(void *obj, int val, int flag);
extern "C" void _Z18TryClearFlags0x130Pht(void *obj, unsigned short flag);
extern "C" void func_ov017_02191108(void *base, int a, int b, int c, int d);
extern "C" void _Z21SetByteSavingPreviousP11Foo02033b58h(void *obj, unsigned char v);
extern "C" void *_Z17GetEntryTableBasev(void);
extern "C" void *_Z21GetElementStride0x318P21Element0x318_02028baci(void *table, int idx);
extern "C" void *_Z24GetCombatantWithFlag0x20P12BattleStructi(void *battle, int idx);
extern "C" void func_ov017_021a23b0(void *base, unsigned short v);
extern "C" void _Z27EnqueueEventTag134_021c9544iiii(int a, int b, int c, int d);
extern "C" int _Z13GetFieldAt0x0Pi(int *ctx);
extern "C" void _Z24UpdatePlayClocks020ac4f8i(int flag);
extern "C" void _Z17SetField5cbcValuePci(void *battle, int v);
extern "C" int _Z17GetField5cbcValuePc(void *battle);

#pragma opt_propagation off

// USA: func_02061c04
// One frame local is shared across case bodies: 0xe7 hands its address to
// CopyOutBattleField0x7ac0 and reads word0 back, 0xd6 writes the three halfwords past it and never
// reads them. Taking the address is what keeps 0xd6's stores alive.
struct SharedFrame { unsigned int word0; unsigned short h4, h6, h8; };
struct Vec3 { int x, y, z; };
// Assigning a struct whose member is an ARRAY emits an inline ldm/stm; a struct of three
// scalars emits an out-of-line helper, and placement new guards the pointer with a cmp.
// This is the only copy form that reaches an EXISTING object in three instructions.
struct Vec3W { int w[3]; };
struct PackedRegSlots7f { unsigned int f0 : 7; unsigned int f1 : 4; unsigned int f2 : 5;
                          unsigned int f3 : 5; unsigned int f4 : 6; };
// The 0x90 list entry. Read as a bitfield, not as `& 0x1ff`: mwcc folds every shift form of a
// 9-bit mask back into `and` against a POOL constant, and the target extracts with lsl #23 / lsr #23.
union SlotEntry { unsigned int w; struct { unsigned int id : 9; unsigned int pad9 : 2; unsigned int slot : 3; } b; };
// Bit 10 of the 0x82/0x83 list entry. Same rule as SlotEntry: a shift or a mask folds to
// `lsr`+`and`; only a bitfield reached through a pointer emits the target's lsl #21 / lsr #31.
struct EntryFlags { unsigned int pad0 : 10; unsigned int bit10 : 1; unsigned int pad11 : 21; };
// Bit 2 of the 0xce element halfword: the target extracts with lsl #29 / lsr #31, which only a
// bitfield through a pointer produces -- `& 4` becomes a `tst`.
struct Elem2Flags { unsigned short pad0 : 2; unsigned short bit2 : 1; unsigned short rest : 13; };

// A second frame local, the one 0xa1 hands to func_020ac2d4/func_020ac104. 0x94 and 0x84 write the
// halfwords past its header and never read them; only the escaping address keeps those stores.
struct FrameB { short opt; unsigned short flags; unsigned short h4, h6, h8, ha, hc, he; };

extern "C" ARM int func_02061c04(void *obj, CmdMsg64 *msg, void *param3) {
    char cdLocal[0xb8];
    struct { int a0, a1, a2, a3; } sa;
    struct { int b0, b1, b2; } sb;
    struct Vec3 halfOut;
    CmdMsg64 m9b;
    CmdMsg64 m9c;
    CmdMsg64 m9d;
    CmdMsg64 m9e;
    CmdMsg64 m9f;
    struct Src021cd6d8 c0Local;
    unsigned short deck[14];
    struct { int a, b, c; } d8Local;
    SafeAllocator dbAlloc;
    struct Vec3 midOut;
    struct Vec3 half;
    struct Vec3 mid;
    struct Vec3 diff;
    struct LowRegion {
        short p1;
        short pad2;
        unsigned int fword0;
        unsigned short fh4, fh6, fh8;
        unsigned char d0, d1;
        short d2;
        unsigned char d3, d4;
        struct FrameB fb;
        struct PackedRegSlots7f packed;
    } lr;
    switch (msg->cmd) {
    case 0x64: {
        SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, msg->p1, 1);
        void *ctx = func_0202ae18();
        if (CheckField0NonZero(ctx) && !GetSearchStructCurrentArrEntry(ctx))
            func_ov017_021d0924(0, 0, msg->p1, 1);
        return 1;
    }
    case 0x65: {
        SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, msg->p1, 0);
        void *ctx = func_0202ae18();
        if (CheckField0NonZero(ctx) && !GetSearchStructCurrentArrEntry(ctx))
            func_ov017_021d0924(0, 0, msg->p1, 0);
        return 1;
    }
    case 0x66: {
        unsigned char slot = *((unsigned char *)obj + 0x332);
        SetOrClearBitInArray(obj, (unsigned char *)obj + slot * 0x1c + 3, msg->p1, 1);
        void *ctx = func_0202ae18();
        if (CheckField0NonZero(ctx) && !GetSearchStructCurrentArrEntry(ctx))
            func_ov017_021d0924(3, *((unsigned char *)obj + 0x332), msg->p1, 1);
        return 1;
    }
    case 0x67: {
        unsigned char slot = *((unsigned char *)obj + 0x332);
        SetOrClearBitInArray(obj, (unsigned char *)obj + slot * 0x1c + 3, msg->p1, 0);
        void *ctx = func_0202ae18();
        if (CheckField0NonZero(ctx) && !GetSearchStructCurrentArrEntry(ctx))
            func_ov017_021d0924(3, *((unsigned char *)obj + 0x332), msg->p1, 0);
        return 1;
    }
    case 0x68: {
        unsigned char slot = *((unsigned char *)obj + 0x332);
        SetOrClearBitInArray(obj, (unsigned char *)obj + slot * 0x1c + 0x10, msg->p1, 1);
        void *ctx = func_0202ae18();
        if (CheckField0NonZero(ctx) && !GetSearchStructCurrentArrEntry(ctx))
            func_ov017_021d0924(5, *((unsigned char *)obj + 0x332), msg->p1, 1);
        return 1;
    }
    case 0x69: {
        unsigned char slot = *((unsigned char *)obj + 0x332);
        SetOrClearBitInArray(obj, (unsigned char *)obj + slot * 0x1c + 0x10, msg->p1, 0);
        void *ctx = func_0202ae18();
        if (CheckField0NonZero(ctx) && !GetSearchStructCurrentArrEntry(ctx))
            func_ov017_021d0924(5, *((unsigned char *)obj + 0x332), msg->p1, 0);
        return 1;
    }
    case 0x6a: {
        void *p = func_ov017_0218b5b0();
        unsigned char *r5 = *(unsigned char **)((char *)p + 0x4000 + 0x4c4);
        ClearNibble0206ece8((int)r5, msg->p1, r5, 0x80);
        ClearNibble0206ece8((int)r5, msg->p1, r5 + 0x80, 0x80);
        return 1;
    }
    case 0x6b: {
        void *ctx = func_0202ae18();
        if (func_0202c508(ctx))
            SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, 0x113a, ((unsigned char *)msg)[2] == 0);
        return 1;
    }
    case 0x6c: {
        void *p0 = func_02012fe4();
        void *node = GetPointerFromArray0x3c((unsigned char *)((char *)p0 + 0x6c), 2);
        while (node) {
            if (*((unsigned char *)node + 0x2c) == msg->p2 &&
                *((unsigned char *)node + 0x2d) == msg->p3 &&
                *(short *)((char *)node + 0x20) == (short)msg->p1) {
                FlagsField0x2e *f = (FlagsField0x2e *)((char *)node + 0x2e);
                if (!(f->flagsHi & 1))
                    f->flagsHi |= 4;
            }
            node = *(void **)((char *)node + 0x70);
        }
        return 1;
    }
    case 0x6d: {
        void *p0 = func_02012fe4();
        void *node = GetPointerFromArray0x3c((unsigned char *)((char *)p0 + 0x6c), 2);
        while (node) {
            FlagsField0x2e *f = (FlagsField0x2e *)((char *)node + 0x2e);
            if (!(f->flagsHi & 1) &&
                *((unsigned char *)node + 0x2c) == msg->p2 &&
                *((unsigned char *)node + 0x2d) == msg->p3 &&
                *(short *)((char *)node + 0x20) == (short)msg->p1) {
                func_02018300(p0, node, 1, 1, 1);
            }
            node = *(void **)((char *)node + 0x70);
        }
        return 1;
    }
    case 0x99: {
        void *p0 = func_02012fe4();
        void *node = GetPointerFromArray0x3c((unsigned char *)((char *)p0 + 0x6c), 2);
        while (node) {
            FlagsField0x2e *f = (FlagsField0x2e *)((char *)node + 0x2e);
            if (!(f->flagsHi & 1) &&
                *((unsigned char *)node + 0x2c) == msg->p2 &&
                *((unsigned char *)node + 0x2d) == msg->p3 &&
                *(short *)((char *)node + 0x20) == (short)msg->p1) {
                f->flagsHi |= 0x100;
                func_02018300(p0, node, 0, 1, 1);
            }
            node = *(void **)((char *)node + 0x70);
        }
        return 1;
    }
    case 0x6e: {
        void *battle = _Z15GetBattleStructv();
        SelectTableValueAndDispatch(battle, msg->p1);
        void *d = GetData02107930();
        *(int *)((char *)d + 0x94) = GetAccumulatedValue(battle);
        *(int *)((char *)d + 0x98) = GetSelectedTableIndex(battle);
        void *ctx = func_0202ae18();
        if (func_0202c508(ctx))
            EnqueueEventTag147_021cdaa0();
        return 1;
    }
    case 0x72:
        msg->p2 = 1;
        AppendNodeToListField30(obj, msg, param3);
        return 1;
    case 0x73:
        msg->p2 = 1;
        AppendNodeToListField30(obj, msg, param3);
        return 1;
    case 0x74:
        AppendNodeToListField30(obj, msg, param3);
        return 1;
    case 0x75:
        AppendNodeToListField30(obj, msg, param3);
        return 1;
    case 0x76:
        AppendNodeToListField30(obj, msg, param3);
        return 1;
    case 0x77:
        AppendNodeToListField30(obj, msg, param3);
        return 1;
    case 0x78:
        AppendNodeToListField30(obj, msg, param3);
        return 1;
    case 0x79: case 0x89: case 0xe1:
        AppendNodeToListField30(obj, msg, param3);
        return 1;
    case 0x7a:
        AppendNodeToListField30(obj, msg, param3);
        return 1;
    case 0x7b:
        AppendNodeToListField30(obj, msg, param3);
        return 1;
    case 0x7c:
        AppendNodeToListField30(obj, msg, param3);
        return 1;
    case 0x7d: {
        if (func_020961b0(GetGlobal02109418(), msg->p1) == 0)
            return 0;
        if (!TestBitInByteArray(obj, (unsigned char *)obj + 0x8c, 0x119d)) {
            void *p = func_ov017_0218b5b0();
            void *list = *(void **)((char *)p + 0x3000 + 0x6fc);
            SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, 0x119d, 1);
            void *node = *(void **)((char *)p + 0x3000 + 0xbc0);
            Init020d9ae8(node, 1);
            AppendNodeToTail(list, node);
        }
        return 1;
    }
    case 0x7e: {
        // The target materialises the comparison into a boolean and then tests it, so the source
        // binds it to a variable rather than branching on the comparison itself.
        int isTwo = _Z20GetPackedNibbleFieldP25PackedNibbleArray0206e120i(obj, msg->p1) == 2;
        if (!isTwo)
            return 1;
        void *p = func_ov017_0218b5b0();
        void *list = *(void **)((char *)p + 0x3000 + 0x6fc);
        void *node = *(void **)((char *)p + 0x3000 + 0xbbc);
        _Z12Init020d9decP14Struct020d9deci(node, 0);
        _Z18SetFlagBit020d9fb4P9S020d9fb4i(node, 0);
        *(int *)((char *)node + 0x10) = msg->p1;
        if (*((unsigned char *)node + 2) == 0)
            AppendNodeToTail(list, node);
        return 1;
    }
    case 0x7f: {
        _Z21RegisterSlotA020cf0fci((int)&sa);
        _Z21RegisterSlotB020cf1a8i((int)&sb);
        lr.packed.f0 = sa.a0;
        lr.packed.f1 = sa.a1;
        lr.packed.f2 = sa.a2;
        lr.packed.f3 = sb.b0;
        lr.packed.f4 = sb.b1;
        void *g = GetGlobal02109418();
        *(unsigned int *)((char *)g + msg->p1 * 4 + 0x178) = *(unsigned int *)&lr.packed;
        _Z23ApplySlotConfig02095cfcii(g, msg->p1);
        return 1;
    }
    case 0x80:
        AppendNodeToListField30(obj, msg, param3);
        return 1;
    case 0x81:
        func_0206e164(obj, msg->p1, 1);
        return 1;
    case 0x82: {
        void *ctx = func_0202ae18();
        if (CheckField0NonZero(ctx)) {
            FindEntryById02096134(GetGlobal02109418(), msg->p1);
            if (!GetSearchStructCurrentArrEntry(ctx)) {
                if (msg->p2 < 0x400)
                    func_ov017_021d0924(0, 0, msg->p2, 1);
                SetBitWithOffset0206eb64(obj, msg->p2, 1);
            } else {
                SetBitWithOffset0206eb64(obj, msg->p2, 1);
            }
        } else {
            SetBitWithOffset0206eb64(obj, msg->p2, 1);
        }
        return 1;
    }
    case 0x83: {
        void *ctx = func_0202ae18();
        if (CheckField0NonZero(ctx)) {
            void *entry = FindEntryById02096134(GetGlobal02109418(), msg->p1);
            if (!GetSearchStructCurrentArrEntry(ctx)) {
                if (!(entry != 0 && ((struct EntryFlags *)entry)->bit10 == 1) &&
                    msg->p2 < 0x400)
                    func_ov017_021d0924(0, 0, msg->p2, 0);
                SetBitWithOffset0206eb64(obj, msg->p2, 0);
            } else {
                if (entry != 0 && ((struct EntryFlags *)entry)->bit10 == 1)
                    SetBitWithOffset0206eb64(obj, msg->p2, 0);
            }
        } else {
            SetBitWithOffset0206eb64(obj, msg->p2, 0);
        }
        return 1;
    }
    case 0x84: {
        void *battle = _Z15GetBattleStructv();
        lr.fb.ha = _Z17GetField5cb0ValuePc(battle);
        lr.fb.hc = _Z17GetField5cb4ValuePc(battle);
        lr.fb.he = _Z17GetField5cb8ValuePc(battle);
        AppendNodeToListField30(obj, msg, param3);
        if (lr.fb.ha != msg->p2)
            _Z20ClearRegions0206e080Pci(obj, *((unsigned char *)obj + 0x332));
        if (lr.fb.hc != msg->p3)
            _Z31ClearIndexedEntryFields0206e0d0Pci(obj, *((unsigned char *)obj + 0x332));
        return 1;
    }
    case 0x85: case 0x8a: case 0xe2:
        AppendNodeToListField30(obj, msg, param3);
        return 1;
    case 0x86: {
        void *ctx = func_0202ae18();
        if (CheckField0NonZero((int *)ctx))
            _Z27EnqueueEventTag141_021ce110itth((unsigned char)msg->p2, 1, msg->p1, 1);
        switch (msg->p2) {
        case 3:
            SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, msg->p1, 1);
            func_ov017_021d0924(0, 0, msg->p1, 1);
            if (func_0202c540(ctx))
                func_0206e748(obj, 0, 0, msg->p1, 1);
            break;
        case 4: {
            SetOrClearBitInArray(obj, (unsigned char *)obj + *((unsigned char *)obj + 0x332) * 0x1c + 3, msg->p1, 1);
            func_ov017_021d0924(3, *((unsigned char *)obj + 0x332), msg->p1, 1);
            if (func_0202c540(ctx)) {
                int slot1 = *((unsigned char *)obj + 0x332);
                func_0206e748(obj, 3, slot1, msg->p1, 1);
            }
            break;
        }
        case 5: {
            SetOrClearBitInArray(obj, (unsigned char *)obj + *((unsigned char *)obj + 0x332) * 0x1c + 0x10, msg->p1, 1);
            func_ov017_021d0924(5, *((unsigned char *)obj + 0x332), msg->p1, 1);
            if (func_0202c540(ctx)) {
                int slot2 = *((unsigned char *)obj + 0x332);
                func_0206e748(obj, 5, slot2, msg->p1, 1);
            }
            break;
        }
        default:
            break;
        }
        return 1;
    }
    case 0x87: {
        void *ctx = func_0202ae18();
        if (CheckField0NonZero((int *)ctx))
            _Z27EnqueueEventTag141_021ce110itth((unsigned char)msg->p2, 0, msg->p1, 1);
        switch (msg->p2) {
        case 3:
            SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, msg->p1, 0);
            func_ov017_021d0924(0, 0, msg->p1, 0);
            if (func_0202c540(ctx))
                func_0206e748(obj, 0, 0, msg->p1, 0);
            break;
        case 4: {
            SetOrClearBitInArray(obj, (unsigned char *)obj + *((unsigned char *)obj + 0x332) * 0x1c + 3, msg->p1, 0);
            func_ov017_021d0924(3, *((unsigned char *)obj + 0x332), msg->p1, 0);
            if (func_0202c540(ctx)) {
                int slot3 = *((unsigned char *)obj + 0x332);
                func_0206e748(obj, 3, slot3, msg->p1, 0);
            }
            break;
        }
        case 5: {
            SetOrClearBitInArray(obj, (unsigned char *)obj + *((unsigned char *)obj + 0x332) * 0x1c + 0x10, msg->p1, 0);
            func_ov017_021d0924(5, *((unsigned char *)obj + 0x332), msg->p1, 0);
            if (func_0202c540(ctx)) {
                int slot4 = *((unsigned char *)obj + 0x332);
                func_0206e748(obj, 5, slot4, msg->p1, 0);
            }
            break;
        }
        default:
            break;
        }
        return 1;
    }
    case 0x88: {
        void *p0 = func_02012fe4();
        void *node = GetPointerFromArray0x3c((unsigned char *)((char *)p0 + 0x6c), 2);
        while (node) {
            if (*((unsigned char *)node + 0x2c) == msg->p2 &&
                *((unsigned char *)node + 0x2d) == msg->p3 &&
                *(short *)((char *)node + 0x20) == (short)msg->p1) {
                FlagsField0x2e *f = (FlagsField0x2e *)((char *)node + 0x2e);
                f->flagsHi &= ~4;
            }
            node = *(void **)((char *)node + 0x70);
        }
        return 1;
    }
    case 0x8b: {
        void *battle = _Z15GetBattleStructv();
        void *p = _Z17GetPtrField0x2a04P12BattleStruct(battle);
        unsigned int v = *(unsigned int *)((char *)p + 0xf6c) + *(unsigned int *)((char *)msg + 4);
        *(unsigned int *)((char *)p + 0xf6c) = v;
        if (v > 9999999)
            *(unsigned int *)((char *)p + 0xf6c) = 9999999;
        return 1;
    }
    case 0x8c: {
        void *battle = _Z15GetBattleStructv();
        void *p = _Z17GetPtrField0x2a04P12BattleStruct(battle);
        unsigned int v = *(unsigned int *)((char *)p + 0xf6c);
        unsigned int d = *(unsigned int *)((char *)msg + 4);
        *(unsigned int *)((char *)p + 0xf6c) = (v < d) ? 0 : (v - d);
        return 1;
    }
    case 0x8d:
        AppendNodeToListField30(obj, msg, param3);
        return 1;
    case 0x8e:
        _Z24SetKeyedArrayBit0206e348Phii(obj, msg->p1, 1);
        return 1;
    case 0x8f: {
        if (msg->p1 == 2)
            return 1;
        void *base = func_ov017_0218b5b0();
        void *mem = ((SafeAllocator *)((char *)base + 0x164))->Allocate(0x30);
        if (mem) {
            func_02012fe4();
            struct Msg8fExt { short cmd, pad2; int f4, f8, fc, f10; int *f14; } *m = (struct Msg8fExt *)msg;
            char *n = (char *)mem;
            *(short *)(n + 0) = (short)m->f4;
            *(int *)(n + 0x14) = m->f8;
            *(int *)(n + 0x1c) = m->f10;
            *(int *)(n + 0x18) = m->fc;
            int *p14 = m->f14;
            *(int *)(n + 0x20) = p14[1];
            *(int *)(n + 0x28) = p14[3];
            *(int *)(n + 0x24) = p14[2];
            *(short *)(n + 2) = (short)(4096.0f * (3.14159274f * (float)p14[4] / 180.0f));
            short angle = *(short *)(n + 2);
            int lim = 0x6488;
            if (angle > lim)
                *(short *)(n + 2) = angle - lim;
            else if (angle < 0)
                *(short *)(n + 2) = angle + 0x6488;

                mid.x = (*(int *)(n + 0x14) + *(int *)(n + 0x20)) >> 1;
            mid.y = (*(int *)(n + 0x18) + *(int *)(n + 0x24)) >> 1;
            mid.z = (*(int *)(n + 0x1c) + *(int *)(n + 0x28)) >> 1;
            *(struct Vec3W *)&midOut = *(struct Vec3W *)&mid;
            *(int *)(n + 4) = midOut.x;
            *(int *)(n + 8) = midOut.y;
            *(int *)(n + 0xc) = midOut.z;

            diff.x = *(int *)(n + 0x14) - *(int *)(n + 0x20);
            diff.y = *(int *)(n + 0x18) - *(int *)(n + 0x24);
            diff.z = *(int *)(n + 0x1c) - *(int *)(n + 0x28);
            *(struct Vec3W *)&half = *(struct Vec3W *)&diff;
            *(struct Vec3W *)&halfOut = *(struct Vec3W *)&half;
            int hx = halfOut.x / 2;
            int hy = halfOut.y / 2;
            int sqy = (int)(((long long)hy * hy + 0x800) >> 12);
            int sqx = (int)(((long long)hx * hx + 0x800) >> 12);
            *(int *)(n + 0x10) = sqx + sqy;
            *(int *)(n + 0x2c) = 0;

            _Z20AppendNodeToField494P8Obj64af8P9Node64af8(obj, mem);
        }
        return 1;
    }
    case 0x90: {
        void *ctx = func_0202ae18();
        if (func_0202c540(ctx))
            return 1;
        int isTwo = _Z20GetPackedNibbleFieldP25PackedNibbleArray0206e120i(obj, msg->p1) == 2;
        if (!isTwo)
            return 1;
        unsigned int *p = (unsigned int *)((char *)GetGlobal02109418() + 4);
        while (p) {
            union SlotEntry *e = (union SlotEntry *)p;
            if (e->b.id == (unsigned short)msg->p1) {
                e->b.slot = msg->p2;
                break;
            }
            p = (unsigned int *)((char *)p + 0x10);
        }
        return 1;
    }
    case 0x91:
        AppendNodeToListField30(obj, msg, param3);
        return 1;
    case 0x92:
        SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0x776, 1);
        return 1;
    case 0x93:
        SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0x776, 0);
        return 1;
    case 0x94: {
        void *battle = _Z15GetBattleStructv();
        lr.fb.h4 = _Z17GetField5cb0ValuePc(battle);
        lr.fb.h6 = _Z17GetField5cb4ValuePc(battle);
        lr.fb.h8 = _Z17GetField5cb8ValuePc(battle);
        msg->p1 = 5;
        AppendNodeToListField30(obj, msg, param3);
        return 1;
    }
    case 0x95: {
        void *p0 = func_02012fe4();
        if (!p0)
            return 0;
        void *entry = _Z23FindEntryByKeys02019508P12Base02019508ii(p0, msg->p1, msg->p2);
        if (!entry) {
            func_0206ea8c(obj, (unsigned char)msg->p1, (short)(msg->p2 + 0x80), 1);
            func_0206ea8c(obj, (unsigned char)msg->p1, (short)msg->p2, 0);
            return 1;
        }
        _Z23SetFlag0x40AndToggle0x4P14Struct02013380ii(entry, msg->p1, 0);
        return 1;
    }
    case 0x96: {
        void *p0 = func_02012fe4();
        if (!p0)
            return 0;
        void *entry = _Z23FindEntryByKeys02019508P12Base02019508ii(p0, msg->p1, msg->p2);
        if (!entry) {
            func_0206ea8c(obj, (unsigned char)msg->p1, (short)(msg->p2 + 0x80), 0);
            func_0206ea8c(obj, (unsigned char)msg->p1, (short)msg->p2, 1);
            return 1;
        }
        _Z23SetFlag0x40AndToggle0x4P14Struct02013380ii(entry, msg->p1, 1);
        return 1;
    }
    case 0x97: {
        void *p = func_ov017_0218b5b0();
        void *list = *(void **)((char *)p + 0x3000 + 0x6fc);
        void *node = *(void **)((char *)p + 0x3000 + 0xb60);
        _Z15InitObj021bdbf0Ph(node);
        *((unsigned char *)node + 0x11) = msg->p1;
        _Z17PrependNodeToHeadP16HeadList020469f8P16HeadNode020469f8(list, node);
        return 1;
    }
    case 0x9b: {
        m9b.cmd = 0x68;
        m9b.p1 = msg->p2;
        func_02061c04(obj, &m9b, param3);
        AppendNodeToListField30(obj, msg, param3);
        return 1;
    }
    case 0x9c: {
        m9c.cmd = 0x7f;
        m9c.p1 = msg->p1;
        func_02061c04(obj, &m9c, param3);
        AppendNodeToListField30(obj, msg, param3);
        return 1;
    }
    case 0x9d: {
        switch ((short)msg->p2) {
        case 0: m9d.cmd = 0x7d; break;
        case 2: m9d.cmd = 0x7f; break;
        case 3: m9d.cmd = 0x81; break;
        default: return 0;
        }
        m9d.p1 = msg->p1;
        func_02061c04(obj, &m9d, param3);
        AppendNodeToListField30(obj, msg, param3);
        return 1;
    }
    case 0x9e: {
        m9e.cmd = 0x75;
        m9e.p1 = msg->p1;
        m9e.p2 = msg->p2;
        return func_02061c04(obj, &m9e, param3);
    }
    case 0x9f: {
        m9f.cmd = 0x74;
        m9f.p1 = msg->p1;
        m9f.p2 = msg->p2;
        return func_02061c04(obj, &m9f, param3);
    }
    case 0xa0:
        SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0x113f, 1);
        return 1;
    case 0xa1: {
        lr.fb.flags &= ~1;
        lr.fb.opt = -1;
        lr.fb.flags &= ~2;
        lr.fb.flags &= ~0xfffcu;
        lr.p1 = msg->p1;
        if (func_020ac2d4(0, &lr.p1, &lr.fb.opt, 1)) {
            lr.fb.flags |= 2;
            func_020ac104(((__typeof__(&data_0211e33c))0x0211E33C), &lr.fb.opt, 1);
        }
        return 1;
    }
    case 0xa2:
        if (msg->p1 != 0)
            SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, 0x113b, 0);
        else
            SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, 0x113b, 1);
        return 1;
    case 0xc0: {
        void *battle = _Z15GetBattleStructv();
        void *p0 = func_02012fe4();
        func_0202ae18();
        c0Local.f0 = 0;
        c0Local.f1 = 0;
        c0Local.f2 = 0;
        c0Local.f3 = 0;
        c0Local.f4 = 0;
        c0Local.f5 = 0;
        c0Local.f7 = 0;
        c0Local.f6 = -1;
        c0Local.f0 = *(unsigned short *)p0;
        c0Local.f1 = msg->p1;
        c0Local.f2 = 0;
        c0Local.f4 = 1;
        c0Local.f3 = -1;
        c0Local.f7 = GetAccumulatedValue(battle);
        _Z27EnqueueEventTag142_021cd6d8P11Src021cd6d8(&c0Local);
        return 1;
    }
    case 0xa4: {
        void *p = func_ov017_0218b5b0();
        func_ov017_021c1a98(p, 0);
        return 1;
    }
    case 0xa5: {
        void *battle = _Z15GetBattleStructv();
        void *combatant = _Z21GetCombatantUncheckedP12BattleStructi(battle, 0);
        _Z18SetBitInArray0x8ecPhi(*(void **)((char *)combatant + 0x150), msg->p1);
        return 1;
    }
    case 0xa6: {
        void *battle = _Z15GetBattleStructv();
        void *combatant = _Z21GetCombatantUncheckedP12BattleStructi(battle, 0);
        _Z18SetBitInArray0x910Phi(*(void **)((char *)combatant + 0x150), msg->p1);
        return 1;
    }
    case 0xa7: {
        unsigned char b = ((unsigned char *)msg)[2];
        if (b == 0)
            _Z27ToggleElemKey2FlagInMap2010i(((unsigned char *)msg)[4]);
        else if (b == 6)
            _Z35SetElemFlag8IfOverlayActive020ae730i(((unsigned char *)msg)[4]);
        return 1;
    }
    case 0xa8:
        return 1;
    case 0xa9:
        if (((unsigned char *)msg)[2] == 0)
            _Z29SetElemFlag0x4PairAndNotify17i(((unsigned char *)msg)[4]);
        return 1;
    case 0xaa:
        _Z29SetElemFlag0x4QuadAndNotify17i((unsigned char)msg->p1);
        return 1;
    case 0xab:
        return 1;
    case 0xac:
        return 1;
    case 0xad:
        return 1;
    case 0xae:
        return 1;
    case 0xaf:
        SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0x1136, 0);
        return 1;
    case 0xb0: {
        void *global = GetGlobal02109418();
        BitFlag17Entry *entry = (BitFlag17Entry *)FindEntryById02096134(global, msg->p1);
        if (entry)
            entry->flag17 = msg->p2;
        return 1;
    }
    case 0xb1: {
        void *battle = _Z15GetBattleStructv();
        SelectTableValueAndDispatch(battle, msg->p2);
        void *d = GetData02107930();
        *(int *)((char *)d + 0x94) = GetAccumulatedValue(battle);
        *(int *)((char *)d + 0x98) = GetSelectedTableIndex(battle);
        _Z13SetActiveFlagP12BattleStructi(battle, msg->p1 == 0);
        return 1;
    }
    case 0xb2: {
        void *base = func_ov017_0218b5b0();
        void *list = *(void **)((char *)base + 0x3000 + 0x6fc);
        void *node = *(void **)((char *)base + 0x3000 + 0xb68);
        _Z19InitContext020e1154Pv((void *)0xbb8);
        func_ov017_021a9bc4(node, ((unsigned char *)msg)[2]);
        func_ov017_021a9a9c(node, ((unsigned char *)msg)[4], ((unsigned char *)msg)[5], msg->p3,
                            ((unsigned char *)msg)[8]);
        AppendNodeToTail(list, node);
        return 1;
    }
    case 0xb3: {
        void *battle = _Z15GetBattleStructv();
        void *p = _Z17GetPtrField0x2a04P12BattleStruct(battle);
        if (msg->p1 != 0) {
            SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, 0x113c, 1);
            *(unsigned int *)((char *)p + 0x2c94) = msg->p2;
        } else {
            SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, 0x113c, 0);
            *(unsigned int *)((char *)p + 0x2c94) = *(unsigned int *)((char *)battle + 0x7e74);
            void *ctx = func_0202ae18();
            if (CheckField0NonZero(ctx) && !GetSearchStructCurrentArrEntry(ctx))
                _Z31EnqueueEventTag23Field_021d0d58v();
        }
        return 1;
    }
    case 0xb4: {
        void *base = func_ov017_0218b5b0();
        void *list = *(void **)((char *)base + 0x3000 + 0x6fc);
        if (!_Z14ListContainsIdP16ListHead02046b60i(list, 0xa))
            return 1;
        void *node = *(void **)((char *)base + 0x3000 + 0x718);
        void *r = func_ov017_021b8478(node);
        if (!_Z21IsField0xcNonNegativePi(r))
            return 1;
        *(short *)((char *)r + 0x22) = (*(int *)((char *)r + 0xc) == msg->p1) ? msg->p2 : 0;
        return 1;
    }
    case 0xb5:
        return 1;
    case 0xb6:
        return 1;
    case 0xb7:
        return 1;
    case 0xb8: {
        void *base = func_ov017_0218b5b0();
        void *list = *(void **)((char *)base + 0x3000 + 0x6fc);
        void *node = *(void **)((char *)base + 0x3000 + 0xb88);
        _Z20InitState60_021aa16cP11Obj021aa16c(node);
        _Z17PrependNodeToHeadP16HeadList020469f8P16HeadNode020469f8(list, node);
        return 1;
    }
    case 0xb9: {
        void *base = func_ov017_0218b5b0();
        _Z18Something_021a6b9cih(base, 0);
        return 1;
    }
    case 0xba:
        SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, 0x1138, msg->p1);
        return 1;
    case 0xbb:
        *(unsigned short *)((char *)obj + 0x2ca) = 0;
        return 1;
    case 0xbc: {
        void *p = _Z27GetStatFieldPointer02064904Pvij(obj, msg->p1, msg->p2);
        if (p) {
            switch (msg->p4) {
            case 0:
                *(unsigned short *)p = msg->p3;
                break;
            case 1: {
                int v = *(unsigned short *)p + msg->p3;
                if (v >= 0xffff)
                    *(unsigned short *)p = 0xffff;
                else
                    *(unsigned short *)p = v;
                break;
            }
            case 2: {
                int v = *(unsigned short *)p - msg->p3;
                if (v < 0)
                    *(unsigned short *)p = 0;
                else
                    *(unsigned short *)p = v;
                break;
            }
            default:
                break;
            }
        }
        return 1;
    }
    case 0xbd: {
        void *base = func_ov017_0218b5b0();
        void *list = *(void **)((char *)base + 0x3000 + 0x6fc);
        void *node = *(void **)((char *)base + 0x3000 + 0x71c);
        func_ov017_021a5568(node);
        _Z26SetBytesAt20And21_021a55a4Phhh(node, 1, ((unsigned char *)msg)[2]);
        *(unsigned char *)((char *)node + 0x24) = 0;
        *(int *)((char *)node + 0x28) = 0;
        *(int *)((char *)node + 0x2c) = -1;
        AppendNodeToTail(list, node);
        return 1;
    }
    case 0xbe: {
        if (!FindEntryById02096134(GetGlobal02109418(), msg->p1))
            break;
        void *p = _Z27GetStatFieldPointer02064904Pvij(obj, msg->p1, msg->p2);
        if (!p)
            return 0;
        *(unsigned short *)p = _Z17NextRandomBetweenP6Randomii(_Z11GetBTRandomv(), msg->p3, msg->p4);
        return 1;
    }
    case 0xbf: {
        unsigned short count = 14;
        int n = 14;
        unsigned short *dst = deck;
        unsigned short *src = (unsigned short *)data_020e7de8;
        do {
            *dst = *src;
            ++src;
            ++dst;
        } while (--n);
        void *entry = FindEntryById02096134(GetGlobal02109418(), msg->p1);
        if (!entry)
            break;
        for (int j = 0; j < 5; j++) {
            int idx = _Z13NextRandomMaxP6Randomi(_Z11GetBTRandomv(), count);
            *(short *)((char *)entry + j * 2 + 4) = deck[idx];
            if (idx < count - 1)
                memmove(&deck[idx], &deck[idx + 1], count - (idx + 1));
            count--;
            deck[count] = 0;
        }
        return 1;
    }
    case 0xc1: {
        void *battle = _Z15GetBattleStructv();
        void *rec = _Z18GetField0x3b0ValueP12BattleStruct(battle);
        if (msg->p1 != 0) {
            _Z33StoreFields0x1e4And0x1e8IfNonZeroPhii(rec, 0x333, 1);
            _Z17SetFlag0x4At0x168Ph(rec);
        } else {
            _Z23ClearTwoWordsAndFlag0x4P21FlagsAndWords0202ea20(rec);
        }
        return 1;
    }
    case 0xc2: {
        void *d = _Z15GetData02108f0cv();
        *(unsigned char *)((char *)d + 0xa8) = msg->p1 * 10;
        return 1;
    }
    case 0xc3:
        func_ov017_0218b5b0();
        return 1;
    case 0xc4:
        return 1;
    case 0xc5: {
        void *battle = _Z15GetBattleStructv();
        void *ctx = func_0202ae18();
        int v = _Z13GetFieldAt0x0Pi((int *)ctx);
        int byte = *((unsigned char *)ctx + 0x1000 + 0xd);
        int flag = 0;
        if ((v == 5 && byte > 1) || v == 6)
            flag = 1;
        _Z24UpdatePlayClocks020ac4f8i(flag);
        int cur = _Z17GetField5cbcValuePc(battle);
        int newVal = msg->p1;
        // The target tests both values against the same 20 id ranges and keeps neither result: each
        // branch converges on the next instruction and no register is written. That is a REDUNDANT
        // store, not a dead one -- a body assigning the value the variable already holds costs no
        // instruction, while a body whose effect dies takes the whole chain with it.
        int a = cur;
        if (cur >= 0xd && cur <= 0xd) a = cur;
        else if (cur >= 0xe && cur <= 0xf) a = cur;
        else if (cur >= 0x10 && cur <= 0x11) a = cur;
        else if (cur >= 0x12 && cur <= 0x18) a = cur;
        else if (cur >= 0x19 && cur <= 0x1b) a = cur;
        else if (cur >= 0x1c && cur <= 0x21) a = cur;
        else if (cur >= 0x22 && cur <= 0x26) a = cur;
        else if (cur >= 0x28 && cur <= 0x5c) a = cur;
        else if (cur >= 0x5d && cur <= 0x5d) a = cur;
        else if (cur >= 0x5e && cur <= 0x64) a = cur;
        else if (cur >= 0x65 && cur <= 0x68) a = cur;
        else if (cur >= 0x69 && cur <= 0x6b) a = cur;
        else if (cur >= 0x6c && cur <= 0x71) a = cur;
        else if (cur >= 0x7b && cur <= 0x7c) a = cur;
        else if (cur >= 0x7d && cur <= 0x80) a = cur;
        else if (cur >= 0x81 && cur <= 0x85) a = cur;
        else if (cur >= 0x86 && cur <= 0x89) a = cur;
        else if (cur >= 0x8a && cur <= 0x8c) a = cur;
        else if (cur >= 0x8d && cur <= 0x92) a = cur;
        else if (cur >= 0x94 && cur <= 0x94) a = cur;
        int b = newVal;
        if (newVal >= 0xd && newVal <= 0xd) b = newVal;
        else if (newVal >= 0xe && newVal <= 0xf) b = newVal;
        else if (newVal >= 0x10 && newVal <= 0x11) b = newVal;
        else if (newVal >= 0x12 && newVal <= 0x18) b = newVal;
        else if (newVal >= 0x19 && newVal <= 0x1b) b = newVal;
        else if (newVal >= 0x1c && newVal <= 0x21) b = newVal;
        else if (newVal >= 0x22 && newVal <= 0x26) b = newVal;
        else if (newVal >= 0x28 && newVal <= 0x5c) b = newVal;
        else if (newVal >= 0x5d && newVal <= 0x5d) b = newVal;
        else if (newVal >= 0x5e && newVal <= 0x64) b = newVal;
        else if (newVal >= 0x65 && newVal <= 0x68) b = newVal;
        else if (newVal >= 0x69 && newVal <= 0x6b) b = newVal;
        else if (newVal >= 0x6c && newVal <= 0x71) b = newVal;
        else if (newVal >= 0x7b && newVal <= 0x7c) b = newVal;
        else if (newVal >= 0x7d && newVal <= 0x80) b = newVal;
        else if (newVal >= 0x81 && newVal <= 0x85) b = newVal;
        else if (newVal >= 0x86 && newVal <= 0x89) b = newVal;
        else if (newVal >= 0x8a && newVal <= 0x8c) b = newVal;
        else if (newVal >= 0x8d && newVal <= 0x92) b = newVal;
        else if (newVal >= 0x94 && newVal <= 0x94) b = newVal;
        if (a != b) {
            char *rec = (char *)battle + 0x104;
            char *snap = rec + 0x7400;
            memset(snap + 0xa4, 0, 0x28);
        }
        _Z17SetField5cbcValuePci(battle, msg->p1);
        return 1;
    }
    case 0xc6: {
        void *ctx = func_0202ae18();
        func_0202c288();
        int lvl = *((unsigned char *)ctx + 0x100d);
        if (lvl <= 1)
            return 0;
        void *base = func_ov017_0218b5b0();
        void *rec = *(void **)((char *)base + 0x3000 + 0x710);
        _Z29ResetFieldsToDefault_021b994cP12Obj_021b994c(rec);
        *((unsigned char *)rec + 0x130) = 1;
        void *battle = _Z15GetBattleStructv();
        int v = *(int *)((char *)battle + 0x5000 + 0x724);
        _Z27EnqueueEventTag153_021d079chht(4, 0, (unsigned short)v);
        *(int *)((char *)rec + 0x12c) = v;
        return 1;
    }
    case 0xc7:
        _Z36NotifyElemAndOverlay17OnFlag020ae990i(msg->p1 & 0xff);
        return 1;
    case 0xc8:
        return 1;
    case 0xc9: {
        unsigned char b = ((unsigned char *)msg)[2];
        if (b <= 7)
            func_020aea40(b, ((unsigned char *)msg)[4]);
        return 1;
    }
    case 0xca:
        SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0x1198, 1);
        return 1;
    case 0xcb: {
        void *battle = _Z15GetBattleStructv();
        void *base = func_ov017_0218b5b0();
        for (int i = 0; i < 4; i++) {
            void *combatant = _Z25GetCombatantWithFlag0x100P12BattleStructi(battle, i);
            if (!combatant)
                continue;
            if (!_Z24CheckField0x56bLowNibbleP11Obj02061bd8(combatant))
                continue;
            int hp = *(unsigned short *)((char *)*(void **)((char *)combatant + 0x130) + 4);
            if (hp > 0)
                continue;
            if (msg->p1 == 0) {
                unsigned short val = *(unsigned short *)((char *)*(void **)((char *)combatant + 0x134) + 0x30);
                _Z21ClearFieldBit02053fe4P9T02053fe4(combatant, val, 1);
            } else if (msg->p1 == 1) {
                int val = *(unsigned short *)((char *)*(void **)((char *)combatant + 0x134) + 0x30);
                _Z21ClearFieldBit02053fe4P9T02053fe4(combatant, val / 2, 1);
            } else {
                _Z21ClearFieldBit02053fe4P9T02053fe4(combatant, 1, 1);
            }
            _Z18TryClearFlags0x130Pht(combatant, 1);
            func_ov017_02191108(base, 1, 1, 1, 1);
            _Z21SetByteSavingPreviousP11Foo02033b58h(combatant, 0);
            *(short *)((char *)combatant + 0xb2) = 0;
        }
        return 1;
    }
    case 0xcc:
        func_ov017_02191484(func_ov017_0218b5b0());
        return 1;
    case 0xcd: {
        void *base = func_ov017_0218b5b0();
        _Z19ResetStruct020d3c08Pc(cdLocal);
        _Z31InitAndMaybeStartStream020d3c28P11Obj020d3c28(cdLocal);
        void *elem = _Z29GetElementCount0xb4Stride0x24Phi(cdLocal, msg->p1);
        if (elem) {
            ElemFlags3Bit0d3d78 *f = (ElemFlags3Bit0d3d78 *)((char *)elem + 0x10);
            func_ov017_021913d0(base, f->field3);
        }
        return 1;
    }
    case 0xce: {
        SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, 0x79a, 1);
        void *ctx = func_0202ae18();
        if (func_0202c508(ctx)) {
            int rowBase;
            void *battle = _Z15GetBattleStructv();
            void *base = func_ov017_0218b5b0();
            void *table = _Z17GetEntryTableBasev();
            for (int a = 0; a < 4; a++) {
                void *elem = _Z21GetElementStride0x318P21Element0x318_02028baci(table, a);
                if (!((struct Elem2Flags *)((char *)elem + 2))->bit2)
                    continue;
                unsigned short val = *(unsigned short *)elem;
                if ((val / 100) * 100 != 400)
                    continue;
                rowBase = a * 0xc + 0x70;
                for (int b = 0; b < 0xc; b++) {
                    void *c2 = _Z24GetCombatantWithFlag0x20P12BattleStructi(battle, b + rowBase);
                    if (!c2)
                        continue;
                    unsigned short v = *(unsigned short *)((char *)c2 + 0x100 + 0x6a);
                    func_ov017_021a23b0(base, v);
                    short p2 = *(short *)((char *)c2 + 2);
                    unsigned short valElem = *(unsigned short *)elem;
                    _Z27EnqueueEventTag134_021c9544iiii(valElem, b, p2, -1);
                }
            }
        }
        return 1;
    }
    case 0xcf: {
        void *pool = &data_02108844;
        if (pool)
            SetOrClearBitInArray(pool, (unsigned char *)pool + 0x8c, 0x384, msg->p1);
        void *base = func_ov017_0218b5b0();
        for (int i = 0; i < 4; i++)
            *(unsigned short *)((char *)base + 0x4400 + i * 2 + 0x4a) =
                *(unsigned short *)((char *)msg + i * 2 + 4);
        return 1;
    }
    case 0xd0: {
        void *ctx = func_0202ae18();
        if (func_0202c508(ctx)) {
            void *battle = _Z15GetBattleStructv();
            void *p = _Z17GetPtrField0x2a04P12BattleStruct(battle);
            *(unsigned int *)((char *)p + 0x2c94) = msg->p1;
            *(unsigned int *)((char *)battle + 0x7e74) = msg->p1;
            _Z31EnqueueEventTag23Field_021d0d58v();
        }
        return 1;
    }
    case 0xd1: {
        void *base = func_ov017_0218b5b0();
        void *ctx = func_0202ae18();
        func_0202c288();
        int lvl = *((unsigned char *)ctx + 0x100d);
        if (lvl <= 1)
            return 1;
        _Z28ResetFieldGroup4444_0218b664Pc(base);
        _Z15GetBattleStructv();
        signed char b = *((signed char *)base + 0x4446);
        _Z27EnqueueEventTag154_021d0860hhh(4, 0, b);
        *((unsigned char *)base + 0x4448) = 1;
        b = *((signed char *)base + 0x4446);
        *((unsigned char *)base + 0x4447) = b;
        return 0;
    }
    case 0xd2: {
        void *base = func_ov017_0218b5b0();
        _Z30SetFieldFromHelper491_02198f70Pvh(base, *((signed char *)base + 0x4446));
        return 1;
    }
    case 0xd3: {
        int bit = msg->p1;
        int one = 1;
        void *p0 = func_02012fe4();
        char *base = (char *)p0 + 0x1840;
        unsigned int *w = (unsigned int *)(base + 0xb4c);
        *w = *w | (one << bit);
        return one;
    }
    case 0xd4:
        func_ov017_0219c520();
        return 1;
    case 0xd5: {
        lr.d0 = 0;
        lr.d1 = 0;
        lr.d2 = 0;
        lr.d3 = 0;
        lr.d4 = 0;
        lr.d0 = (msg->p2 == 0);
        lr.d1 = (msg->p3 == 0);
        lr.d2 = msg->p4;
        lr.d3 = (msg->p5 == 0);
        void *base = func_ov017_0218b5b0();
        _Z25SetName56AndFlag_0218d7b0PhPc(base, (char *)&lr.d0);
        return 1;
    }
    case 0xd6: {
        void *battle = _Z15GetBattleStructv();
        lr.fh4 = _Z17GetField5cb0ValuePc(battle);
        lr.fh6 = _Z17GetField5cb4ValuePc(battle);
        lr.fh8 = _Z17GetField5cb8ValuePc(battle);
        AppendNodeToListField30(obj, msg, param3);
        return 1;
    }
    case 0xd7: {
        void *base = func_ov017_0218b5b0();
        func_ov017_021a8614(base, (short)msg->p1, msg->p2, msg->p3, msg->p4, msg->p5);
        return 1;
    }
    case 0xd8: {
        int p1 = *(short *)((char *)msg + 2);
        void *ctx = func_0202ae18();
        if (func_0202c508(ctx)) {
            void *p0 = func_02012fe4();
            *(short *)((char *)p0 + 0x2700 + 0xb4) = p1;
            if (CheckField0NonZero((int *)ctx)) {
                _Z40SetHalfFieldsAndEnqueueIfActive_021d1c2ctt((unsigned char)p1, 0);
                _Z26EnqueueEventTagB5_021d1dc0ssPisi((unsigned short)p1, 0, (int *)&d8Local, 0, 0);
            }
        }
        return 1;
    }
    case 0xd9: {
        void *p = func_ov017_0218b5b0();
        void *list = *(void **)((char *)p + 0x3000 + 0x6fc);
        void *node = *(void **)((char *)p + 0x3000 + 0xb6c);
        _Z15InitObj021beba4Pc(node);
        AppendNodeToTail(list, node);
        return 1;
    }
    case 0xda:
        func_020732cc(msg->p1);
        return 1;
    case 0xdb: {
        dbAlloc.ResetAllocatorPointer();
        dbAlloc.ResetAllocatorPointer();
        void *mem = AllocateAligned4(&data_02114e20, 0x1000);
        dbAlloc.CreateTypeA(mem, 0x1000);
        dbAlloc.Reset();
        void *battle = _Z15GetBattleStructv();
        void *p = _Z17GetPtrField0x2a04P12BattleStruct(battle);
        void *r = func_02086f24(p, (unsigned char)msg->p1, &dbAlloc);
        void *signedAlloc = dbAlloc.GetSignedAllocator();
        if (signedAlloc) {
            dbAlloc.Destroy();
            TailForward02012da4(&data_02114e20, signedAlloc);
        }
        return (int)r;
    }
    case 0xdc:
        func_020aee04(msg->p1, ((unsigned char *)msg)[4]);
        return 1;
    case 0xdd: {
        void *p = func_ov017_0218b5b0();
        func_ov017_021c1a98(p, 1);
        return 1;
    }
    case 0xde: {
        void *p0 = func_02012fe4();
        *((unsigned char *)p0 + 0x2000 + 0x7d0) = 0;
        return 1;
    }
    case 0xdf:
        SetOrClearBitInArray(&data_02108844, (unsigned char *)&data_02108844 + 0x8c, 0x799, msg->p1);
        return 1;
    case 0xe0:
        SetOrClearBitInArray(&data_02108844, (unsigned char *)&data_02108844 + 0x8c, 0x798, msg->p1);
        return 1;
    case 0xe3: {
        void *p = func_ov017_0218b5b0();
        (void)p;
        _Z27InitAndAppendEntity020dac40P12Root020dac40();
        return 1;
    }
    case 0xe4: {
        unsigned char *p = (unsigned char *)&data_02109bf4 + 0xc8;
        unsigned int v = (unsigned int)(msg->p1 == 0);
        unsigned int s = (v << 31) >> 29;
        unsigned int b = *p;
        *p = (unsigned char)((b & ~4u) | s);
        return 1;
    }
    case 0xe5: {
        void *battle = _Z15GetBattleStructv();
        unsigned short s5 = *(unsigned short *)((char *)battle + 0x7100 + 0xdc);
        short s6 = *(short *)((char *)battle + 0x7100 + 0xde);
        short s7 = *(short *)((char *)battle + 0x7100 + 0xe0);
        void *p = _Z17GetPtrField0x2a04P12BattleStruct(battle);
        if (s5 == 0)
            return 1;
        if (s6 >= 0 && s6 <= 3) {
            void *combatant = _Z25GetCombatantWithFlag0x100P12BattleStructi(battle, s6);
            if (!combatant)
                return 1;
            void *field = _Z15GetFieldAt0x150Ph(combatant);
            _Z27RemoveSlotShiftDown0208386cP13Slots0208386ci(field, (signed char)s7);
        } else {
            _Z25DecrementKeyValue020a0a08P14KeyMap020a0a08ii(p, (short)s5, 1);
        }
        return 1;
    }
    case 0xe6:
        SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0xbea, msg->p2);
        return 1;
    case 0xe7: {
        void *ctx = func_0202ae18();
        if (func_0202c540(ctx))
            return 1;
        SetOrClearBitInArray(obj, (unsigned char *)obj + 0x8c, 0x796, msg->p1);
        void *battle = _Z15GetBattleStructv();
        char *e7base = (char *)battle + 0x104;
        char *rec = e7base + 0x7400;
        int snapOff = 0xcc;
        struct SnapshotE7 *snap = (struct SnapshotE7 *)(rec + snapOff);
        if (!snap->done) {
            void *fields = _Z17GetPtrField0x2a04P12BattleStruct(battle);
            unsigned short level = 0;
            void *comb = _Z24GetCombatantAtField0x3acP12BattleStruct(battle);
            if (comb)
                level = *(unsigned short *)((char *)*(void **)((char *)comb + 0x134) + 0x30);
            lr.fword0 = 0;
            _Z24CopyOutBattleField0x7ac0Pv((void *)&lr.fword0);
            _Z23CopyHalfwordAndTwoBytesP19SmallRecord020643e0S0_(snap, rec + 0x3c);
            _Z23CopyHalfwordAndTwoBytesP19SmallRecord020643e0S0_((char *)snap + 4, rec + 0x40);
            snap->a_lo = ((struct SrcWord44 *)(rec + 0x44))->v24;
            snap->a_mid = _Z22GetFieldPercentOver307P7S_a0870(rec + 0x3c);
            snap->a_hi = _Z22GetFieldPercentOver448P7S_a090c(rec + 0x3c);
            snap->b_lo = lr.fword0;
            snap->b_mid = _Z22GetFieldPercentOver232P7S_a08a4(rec + 0x3c);
            snap->b_hi = _Z22GetFieldPercentOver944P7S_a08d8(rec + 0x3c);
            snap->c_lo = ((struct SrcWord4c *)(rec + 0x4c))->v9;
            snap->c_mid = ((struct SrcWord48 *)(rec + 0x48))->v14;
            snap->d_lo = ((struct SrcWord44 *)(rec + 0x44))->hi8;
            snap->d_mid = ((struct SrcWord4c *)(rec + 0x4c))->v14;
            snap->d_hi = level;
            snap->e_lo = ((struct SrcWord44 *)(rec + 0x7c))->v24;
            snap->total = *(unsigned int *)((char *)fields + 0xf6c) + *(unsigned int *)((char *)fields + 0xf68);
            snap->done = 1;
        }
        return 1;
    }
    case 0xe8: {
        void *g = _Z20GetGlobalPtr021075f4v();
        void *entry = _Z29FindEntryPointerByKey0203df78Pvi(g, msg->p1);
        if (!entry)
            return 1;
        void *f = _Z19GetField0xc02040538P9S02040538(entry);
        if (!f)
            return 1;
        unsigned char b = *((unsigned char *)f + 0xa);
        b = (b & ~0x38) | (((unsigned char)msg->p2 & 7) << 3);
        *((unsigned char *)f + 0xa) = b;
        return 1;
    }
    case 0xe9:
        _Z21SyncEightElementFlagsv();
        return 1;
    case 0x6f: case 0x70: case 0x71: case 0x98: case 0x9a: case 0xa3:
        break;
    default:
        break;
    }
    return 0;
}
