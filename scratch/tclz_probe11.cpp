#include <globaldefs.h>

ARM void FillWordsProbe11(int val, int p, int byteLen) {
    int end = p + byteLen;
    do {
        if (p < end) {
            *(int*)p = val;
        }
        if (p < end) {
            p += 4;
        }
    } while (p < end);
}
