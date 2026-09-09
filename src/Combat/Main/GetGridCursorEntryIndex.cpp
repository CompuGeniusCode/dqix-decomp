#include <globaldefs.h>

struct Struct_0205bb84 {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int* field24;
    int* field28;
    int* field2C;
};

// Recombines the grid cursor's page (+0x14) and its two in-page coordinates (*+0x28, *+0x2c) into
// the flat entry index, with *+0x24 the count along the *+0x2c axis and +0x8 * +0xc the page size.
// It is the exact inverse of the decomposition at 0x0205bb04. The touchscreen hit test in
// func_0205bd78 feeds it, and func_0205d794 reaches it through func_0205bd04, which returns -1
// unless the active byte at +0x4e is set. The 16-bit truncation on both halves is in the
// original; it only matters past 0x7fff entries.
extern "C" ARM int GetGridCursorEntryIndex(struct Struct_0205bb84* s) {
    int p = *s->field24 * *s->field28 + *s->field2C;
    int q = s->field14 * s->fieldC * s->field8;
    return (short)q + (short)p;
}
