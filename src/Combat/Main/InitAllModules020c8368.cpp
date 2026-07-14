#include <globaldefs.h>

extern "C" void func_020c83b0(void);
void CallFunc020cad24_020cad18(void);
extern "C" void func_020c6d7c(void);
extern "C" void func_020c84b4(void);
void ResetPairAt027e0060(void);
void StoreSharedMemMagicWords(void);
extern "C" void func_020c8a3c(void);
void SetWramCntThenReset(void);
void InitModule020c9288(void);
void ResetTable020c9a54(void);
extern "C" void func_020c745c(void);
extern "C" void func_020c983c(void);
extern "C" void func_020d15fc(void);
extern "C" void func_020d0ec4(void);
extern "C" void func_020ce270(void);
void WaitForVCountZero(void);

// USA: func_020c8368
ARM void InitAllModules020c8368(void) {
    func_020c83b0();
    CallFunc020cad24_020cad18();
    func_020c6d7c();
    func_020c84b4();
    ResetPairAt027e0060();
    StoreSharedMemMagicWords();
    func_020c8a3c();
    SetWramCntThenReset();
    InitModule020c9288();
    ResetTable020c9a54();
    func_020c745c();
    func_020c983c();
    func_020d15fc();
    func_020d0ec4();
    func_020ce270();
    WaitForVCountZero();
}
