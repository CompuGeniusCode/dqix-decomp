#include <globaldefs.h>

ARM void FillWordsProbe9(int val, int* p, int byteLen) {
    int* end = (int*)((char*)p + byteLen);
    while (p < end) {
        *p++ = val;
    }
}
