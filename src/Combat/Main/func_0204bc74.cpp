#include <globaldefs.h>

struct TileMap0204bc74 {
    char pad[0x14];
    unsigned short (*rows)[32];
};

// USA: func_0204bc74  (semantic: FillTileMapRegion0204bc74)
extern "C" ARM void func_0204bc74(struct TileMap0204bc74 *obj, unsigned short tile, int x, int y, int w, int h, unsigned short palette) {
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
