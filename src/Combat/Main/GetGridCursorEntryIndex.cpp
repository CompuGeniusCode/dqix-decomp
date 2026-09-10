#include <globaldefs.h>

struct GridCursor {
    int entryCount;
    int unknown4;
    int dimA;
    int dimB;
    int fillOrder;
    int page;
    int coordA;
    int coordB;
    int outerCount;
    int* innerCount;
    int* outerCoord;
    int* innerCoord;
};

// Recombines the grid cursor page (+0x14) and its two in-page coordinates (*+0x28, *+0x2c) into
// the flat entry index, with *+0x24 the count along the *+0x2c axis and +0x8 * +0xc the page size.
// It is the exact inverse of SetGridCursorFromEntryIndex at 0x0205bb04. The touchscreen hit test in
// func_0205bd78 feeds it, and GetMenuCursorIndex reaches it through func_0205bd04, which returns -1
// unless the active byte at +0x4e is set. The 16-bit truncation on both halves is in the
// original; it only matters past 0x7fff entries.
extern "C" ARM int GetGridCursorEntryIndex(struct GridCursor* cursor) {
    int indexInPage = *cursor->innerCount * *cursor->outerCoord + *cursor->innerCoord;
    int pageBase = cursor->page * cursor->dimB * cursor->dimA;
    return (short)pageBase + (short)indexInPage;
}
