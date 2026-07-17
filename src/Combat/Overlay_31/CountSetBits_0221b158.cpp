#include <globaldefs.h>

// USA: func_ov031_0221b158
ARM int CountSetBits_0221b158(unsigned char* p) {
    int count = 0;
    int i = 0;
    do {
        int bit = 0;
        unsigned char b = p[i];
        do {
            if ((b >> bit) & 1) {
                count++;
            }
            bit++;
        } while (bit < 8);
        i++;
    } while (i < 4);
    return count & 0xff;
}
