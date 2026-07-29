#include <globaldefs.h>

// USA: func_020ca3ec
ARM void FillWords_020ca3ec(int val, void* dst, int len) {
    int* p = (int*)dst;
    int* end = (int*)((char*)dst + len);
    if (p < end) {
        do {
            *p++ = val;
        } while (p < end);
    }
}
