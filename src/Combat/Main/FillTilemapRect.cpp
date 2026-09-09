#include <globaldefs.h>

struct TileMap0204bc74 {
    char pad[0x14];
    unsigned short (*rows)[32];
};

// Fills a rectangle of background map entries. Each entry keeps the low twelve bits of `tile`
// (tile number plus the two flip bits) and takes the palette in bits 12-15; a palette of 0xffff
// means leave it at zero rather than select palette 15. The fill is clipped to 32 columns and 25
// rows rather than rejected -- the 32 is the row stride, the 25 only this function's own bound.
// The clip arithmetic truncates to short, so a rectangle whose width or height does not fit in a
// short will wrap instead of clamping.
extern "C" ARM void FillTilemapRect(struct TileMap0204bc74 *obj, unsigned short tile, int x, int y, int w, int h, unsigned short palette) {
    unsigned short (*rows)[32] = obj->rows;
    if (rows == 0) {
        return;
    }
    if (x + w <= 0 || y + h <= 0) {
        return;
    }
    if (x >= 0x20 || y >= 0x19) {
        return;
    }

    if (x < 0) {
        w = (short)(x + w);
        x = 0;
    } else if (x + w >= 0x20) {
        w = (short)(0x20 - x);
    }

    if (y < 0) {
        h = h + y;
        h = (short)h;
        y = 0;
    } else if (y + h >= 0x19) {
        h = (short)(0x19 - y);
    }
    unsigned short *row = rows[y] + x;
    if (palette != 0xffff) {
        palette = palette << 12;
    } else {
        palette = 0;
    }
    tile = tile & 0xfff;
    tile |= palette;

    short j = 0;
    short i;
    while (j < h) {
        i = 0;
        while (i < w) {
            row[i] = tile;
            i = i + 1;
        }
        row += 32;
        j = j + 1;
    }
}
