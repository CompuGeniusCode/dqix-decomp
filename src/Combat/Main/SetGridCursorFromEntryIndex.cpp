#include <globaldefs.h>

struct SelfBB04 {
    int f0;
    char pad4[4];
    int f8;
    int fc;
    char pad10[4];
    int f14;
    char pad18[0x24 - 0x18];
    int* f24;
    int* f28;
    int* f2c;
};

// Splits a flat entry index into the page, row and column of a paged selection grid. Items per page
// is the product of the two dimensions at +0x8 and +0xc, and the pointers at +0x24..+0x2c decide
// which of the two the division runs over, so mode 1 in func_0205ba68 turns the same
// grid column-major. It is the exact inverse of func_0205bb84, which rebuilds the index
// that func_0205bd78 derives by hit-testing the input coordinates - seemingly the touch panel -
// against the per-cell rectangles. Which menus use it is not established.
extern "C" ARM void SetGridCursorFromEntryIndex(struct SelfBB04* self, int value) {
    if (value < 0) return;
    if (value >= self->f0) return;
    int product = self->fc * self->f8;
    if (product == 0) return;
    self->f14 = value / product;
    value = value % product;
    *self->f2c = value % *self->f24;
    *self->f28 = value / *self->f24;
}
