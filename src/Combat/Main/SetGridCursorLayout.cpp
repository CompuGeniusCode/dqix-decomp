#include <globaldefs.h>

struct GridCursor {
    int entryCount;
    int unknown4;
    int dimA;
    int dimB;
    unsigned char fillOrder;
    int page;
    int coordA;
    int coordB;
    int* outerCount;
    int* innerCount;
    int* outerCoord;
    int* innerCoord;
};

// Sets the two dimensions of one grid cursor, and its fill order. The four pointers at +0x20..+0x2c alias
// the dimension pair at +0x8/+0xc and the coordinate pair at +0x18/+0x1c, swapped when mode is 1,
// so that SetGridCursorFromEntryIndex -- which divides an entry index by *+0x24 and writes quotient and remainder
// through *+0x28 and *+0x2c -- and GetGridCursorEntryIndex, which runs that back to an index, do their
// arithmetic without knowing whether entries run across then down or down then across. Which
// dimension is the column count is not established; modes other than 0 or 1 change nothing.
// +0x8 always travels with +0x18 and +0xc with +0x1c, whichever way the mode points them, which is
// why the two are named as one pair rather than as rows and columns.
extern "C" ARM void SetGridCursorLayout(struct GridCursor* cursor, int dimA, int dimB, int mode) {
    cursor->dimA = dimA;
    cursor->dimB = dimB;
    cursor->fillOrder = mode;
    if (mode == 0) {
        cursor->outerCount = &cursor->dimA;
        cursor->innerCount = &cursor->dimB;
        cursor->outerCoord = &cursor->coordA;
        cursor->innerCoord = &cursor->coordB;
    } else if (mode == 1) {
        cursor->outerCount = &cursor->dimB;
        cursor->innerCount = &cursor->dimA;
        cursor->outerCoord = &cursor->coordB;
        cursor->innerCoord = &cursor->coordA;
    }
}
