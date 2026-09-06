#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0();
extern "C" int _Z27GetField24ThenCall_021b2074Pv(void* obj, void* extra);

// USA: func_ov003_02172570  (semantic: CallCallbackIfState9_02172570)
extern "C" ARM int func_ov003_02172570(unsigned char* obj, void* extra) {
    if (*obj != 9) {
        return 0;
    }
    char* base = (char*)func_ov017_0218b5b0();
    _Z27GetField24ThenCall_021b2074Pv(*(void**)(base + 0x3b48), extra);
    return 1;
}
