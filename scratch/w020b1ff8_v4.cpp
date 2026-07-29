#include <globaldefs.h>

// USA: func_020b1ff8
ARM void FillIndexGrid020b1ff8(unsigned short* dst, int cols, int rows, int rowPitch, int startIndex, int flag) {
    unsigned int hi = (unsigned int)flag << 28;
    int index = startIndex;
    int row = 0;
    if (rows > 0) {
        do {
            int col = 0;
            unsigned short* p = dst;
            if (cols > 0) {
                do {
                    col++;
                    *p++ = (unsigned short)((hi >> 16) | index);
                    index++;
                } while (col < cols);
            }
            row++;
            dst += rowPitch;
        } while (row < rows);
    }
}
