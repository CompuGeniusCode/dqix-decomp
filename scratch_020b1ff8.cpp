#include <globaldefs.h>

// USA: func_020b1ff8
ARM void FillPaletteGradient020b1ff8(unsigned short* dst, int width, int height, int stride, unsigned int color, unsigned int hiBits) {
    int row = 0;
    unsigned int hi = hiBits << 28;
    if (height <= 0) {
        return;
    }
    do {
        int col = 0;
        unsigned short* p = dst;
        if (width > 0) {
            do {
                unsigned int val = color | (hi >> 16);
                col++;
                color++;
                *p++ = val;
            } while (col < width);
        }
        row++;
        dst += stride;
    } while (row < height);
}
