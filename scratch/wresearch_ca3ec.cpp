#include <globaldefs.h>

ARM void FillWords_020ca3ec(int val, int* dst, int len) {
    int* end = (int*)((char*)dst + len);
    do {
        if (dst < end) {
            *dst++ = val;
        }
    } while (dst < end);
}
