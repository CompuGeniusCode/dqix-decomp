#include <globaldefs.h>

// USA: func_02000954
ARM void func_02000954(int val, int* p, int len) {
    int* end = (int*)((char*)p + len);
    while (p < end) {
        *p++ = val;
    }
}
