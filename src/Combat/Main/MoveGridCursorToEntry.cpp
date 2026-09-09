#include <globaldefs.h>

extern "C" void SetGridCursorFromEntryIndex(void*, int);

struct Struct_0205bcdc {
    int field0;
    char pad[0x2c];
    int field30;
};

// Public entry point for jumping the grid cursor to an entry: it bounds-checks the index against
// the entry count at +0x0 and hands it to SetGridCursorFromEntryIndex (0x0205bb04), which splits
// it into a page plus two axis components, the count for one of them at *+0x24. It also stores -1
// into +0x30 first, clearing the current selection func_0205bc2c keeps there before repositioning.
extern "C" ARM void MoveGridCursorToEntry(struct Struct_0205bcdc* s, int index) {
    if (index < 0) return;
    if (s->field0 <= index) return;
    s->field30 = -1;
    SetGridCursorFromEntryIndex(s, index);
}
