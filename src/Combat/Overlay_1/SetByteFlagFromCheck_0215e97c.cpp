#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* obj);
int GetGlobalField0x1c020421a0(void);

// USA: func_ov001_0215e97c
ARM int SetByteFlagFromCheck_0215e97c(void* obj) {
    int base = GetGlobalField0x1c020421a0();
    int v = func_ov017_021d60f4(obj);
    unsigned char flag = (v != 0) ? 1 : 0;
    *(unsigned char*)((char*)base + 0x1000 + 0x9cb) = flag;
    return 1;
}
