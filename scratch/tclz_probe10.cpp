#include <globaldefs.h>

ARM void FillWordsProbe10(int val, int p, int byteLen) {
    int end = p + byteLen;
    while (p < end) {
        *(int*)p = val;
        p += 4;
    }
}
