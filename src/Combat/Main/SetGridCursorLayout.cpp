#include <globaldefs.h>

struct Struct_0205ba68 {
    int field0;
    int field4;
    int field8;
    int fieldC;
    unsigned char field10;
    int field14;
    int field18;
    int field1C;
    int* field20;
    int* field24;
    int* field28;
    int* field2C;
};

// Sets a grid cursor's two dimensions and its fill order. The four pointers at +0x20..+0x2c alias
// the dimension pair at +0x8/+0xc and the coordinate pair at +0x18/+0x1c, swapped when mode is 1,
// so that SetGridCursorFromEntryIndex -- which divides an entry index by *+0x24 and writes quotient and remainder
// through *+0x28 and *+0x2c -- and GetGridCursorEntryIndex, which runs that back to an index, do their
// arithmetic without knowing whether entries run across then down or down then across. Which
// dimension is the column count is not established; modes other than 0 or 1 change nothing.
extern "C" ARM void SetGridCursorLayout(struct Struct_0205ba68* s, int a, int b, int mode) {
    s->field8 = a;
    s->fieldC = b;
    s->field10 = mode;
    if (mode == 0) {
        s->field20 = &s->field8;
        s->field24 = &s->fieldC;
        s->field28 = &s->field18;
        s->field2C = &s->field1C;
    } else if (mode == 1) {
        s->field20 = &s->fieldC;
        s->field24 = &s->field8;
        s->field28 = &s->field1C;
        s->field2C = &s->field18;
    }
}
