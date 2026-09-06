#include <globaldefs.h>

extern "C" void* func_02012fe4(void);
extern "C" int func_ov017_021d60f4(void*);

// USA: func_ov001_02161f3c
ARM int SetGlobalOffset2750FromArg_02161f3c(void* obj) {
    void* g = func_02012fe4();
    int v = func_ov017_021d60f4(obj);
    *(int*)((char*)g + 0x2750) = v;
    return 1;
}
