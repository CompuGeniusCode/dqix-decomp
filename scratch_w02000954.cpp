#include <globaldefs.h>

// USA: func_02000954
ARM void FillWords_02000954(int val, void* dst, int len) {
    int* p = (int*)dst;
    int end = (int)dst + len;
L1:
    if (!((int)p < end)) goto L3;
    *p++ = val;
L3:
    if ((int)p < end) goto L1;
}
