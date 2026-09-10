#include <globaldefs.h>

extern int data_02109418;

// Hands back the single global at 0x02109418. func_02095578 loads data/scenario/questorder3.bin --
// the same file the curated BeginLoadQuestOrderTable at 0x02095e90 names -- and runs it as a script
// that fills the global; the layout is a count byte at +0 and 0x10-byte entries from +4, which is
// what func_02096134 indexes. Callers pass the result to that search, which matches a 9-bit
// quest id and rejects anything above 0xcc; 0x0209d1a4 accumulates the entry's halfword at +0xa and
// clamps it at 0xffff.
extern "C" ARM int* GetQuestOrderTable(void) {
    return &data_02109418;
}
