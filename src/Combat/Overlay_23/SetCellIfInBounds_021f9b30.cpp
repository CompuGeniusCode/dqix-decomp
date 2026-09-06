#include <globaldefs.h>

struct Grid021f9b30 {
    char pad[0x20];
    short* cells;
    unsigned short width;
    unsigned short height;
};

// USA: func_ov023_021f9b30
ARM int SetCellIfInBounds_021f9b30(struct Grid021f9b30* self, short val, unsigned int x, unsigned int y) {
    if (self->cells == NULL) {
        return 0;
    }
    if (!(self->width > x && self->height > y)) {
        return 0;
    }
    self->cells[x * self->height + y] = val;
    return 1;
}
