#include <globaldefs.h>

// USA: func_020b1ff8
ARM void FillIndexGrid020b1ff8(unsigned short* dst, int cols, int rows, int rowPitch, int startIndex, int flag) {
    int row = 0;
    int index = startIndex;
    unsigned int hi = (unsigned int)flag << 28;
    if (rows > 0) {
        do {
            unsigned short* p = dst;
            int col = row;
            if (cols > 0) {
                do {
                    index++;
                    col++;
                    *p++ = (unsigned short)((hi >> 16) | index);
                } while (col < cols);
            }
            row++;
            dst += rowPitch;
        } while (row < rows);
    }
}
