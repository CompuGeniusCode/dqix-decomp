#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
extern "C" int func_ov017_021d60f4(void* obj);

// USA: func_ov001_021631a4
ARM int SetFieldFromOv17Result_021631a4(void* obj) {
    char* base = (char*)func_ov017_0218b5b0();
    char* q = *(char**)(base + 0x3000 + 0x734);
    int v = func_ov017_021d60f4(obj);
    *(short*)(q + 0x100 + 0x84) = (short)v;
    return 1;
}
