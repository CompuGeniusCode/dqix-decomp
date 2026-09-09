#include <globaldefs.h>

struct Struct_0205bb84;
extern "C" int GetGridCursorEntryIndex(struct Struct_0205bb84* s);
extern "C" void SetGridCursorFromEntryIndex(void* s, int n);

struct Node0205bacc {
    int field0;
};

// Sets how many items the cursor grid holds, and pulls the cursor back to the last item when it
// would otherwise sit past the end. The struct is the 2D cursor of SetGridCursorLayout, which keeps
// columns at +0x8 and rows at +0xc and points +0x20..+0x2c at one pair or the other depending on
// whether the grid runs in row or column order; GetGridCursorEntryIndex folds page, row and
// column back into a linear index and SetGridCursorFromEntryIndex splits one apart again. A negative count is
// ignored outright.
extern "C" ARM void SetGridItemCountAndClampCursor(struct Node0205bacc* s, int val) {
    if (val < 0) return;
    s->field0 = val;
    if (GetGridCursorEntryIndex((struct Struct_0205bb84*)s) < val) return;
    SetGridCursorFromEntryIndex(s, val - 1);
}
