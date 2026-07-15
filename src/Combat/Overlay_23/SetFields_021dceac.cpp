#include <globaldefs.h>

// USA: func_ov023_021dceac
ARM void SetFields_021dceac(char* obj, int idx, int val, unsigned char b1, unsigned char b2, unsigned char b3) {
    *(int*)(obj + 0x784 + idx * 4) = val;
    *(unsigned char*)(obj + 0x790 + idx) = b1;
    *(unsigned char*)(obj + 0x793 + idx) = b2;
    *(unsigned char*)(obj + 0x796 + idx) = b3;
}
