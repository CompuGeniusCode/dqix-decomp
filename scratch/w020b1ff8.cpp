#include <globaldefs.h>

// USA: func_020b1ff8
ARM void FillIndexGrid020b1ff8(unsigned short* dst, int cols, int rows, int rowPitch, int startIndex, int flag) {
    unsigned int hi = (unsigned int)flag << 28;
    int index = startIndex;
    if (rows > 0) {
        int row = 0;
        do {
            unsigned short* p = dst;
            if (cols > 0) {
                int col = 0;
                do {
                    *p++ = (unsigned short)((hi >> 16) | index);
                    col++;
                    index++;
                } while (col < cols);
            }
            dst += rowPitch;
            row++;
        } while (row < rows);
    }
}
