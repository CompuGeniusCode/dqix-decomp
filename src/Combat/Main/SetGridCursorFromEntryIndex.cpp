#include <globaldefs.h>

struct GridCursor {
    int entryCount;
    char unknown4[4];
    int dimA;
    int dimB;
    char fillOrder[4];
    int page;
    char unknown18[0x24 - 0x18];
    int* innerCount;
    int* outerCoord;
    int* innerCoord;
};

// Splits a flat entry index into the page, row and column of a paged selection grid. Items per page
// is the product of the two dimensions at +0x8 and +0xc, and the pointers at +0x24..+0x2c decide
// which of the two the division runs over, so mode 1 in SetGridCursorLayout turns the same
// grid column-major. It is the exact inverse of GetGridCursorEntryIndex, which rebuilds the index
// that func_0205bd78 derives by hit-testing the input coordinates - seemingly the touch panel -
// against the per-cell rectangles. The count it bounds-checks against at +0x0 is the one
// SetGridItemCountAndClampCursor sets, and the bytes skipped here are the fill order at +0x10 and
// the coordinate pair at +0x18/+0x1c that the pointers at +0x28 and +0x2c alias. Which menus use it
// is not established.
extern "C" ARM void SetGridCursorFromEntryIndex(struct GridCursor* cursor, int entryIndex) {
    if (entryIndex < 0) return;
    if (entryIndex >= cursor->entryCount) return;
    int entriesPerPage = cursor->dimB * cursor->dimA;
    if (entriesPerPage == 0) return;
    cursor->page = entryIndex / entriesPerPage;
    entryIndex = entryIndex % entriesPerPage;
    *cursor->innerCoord = entryIndex % *cursor->innerCount;
    *cursor->outerCoord = entryIndex / *cursor->innerCount;
}
