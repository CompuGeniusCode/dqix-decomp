#include <globaldefs.h>

extern "C" unsigned char* func_0205ec34(void);

// USA: func_02010774
ARM void SetField5cb0AndRecordByte0(char* obj, int v) {
    *(int*)(obj + 0x5cb0) = v;
    unsigned char* p = func_0205ec34();
    p[p[0x332] * 0x1c] = v;
}
