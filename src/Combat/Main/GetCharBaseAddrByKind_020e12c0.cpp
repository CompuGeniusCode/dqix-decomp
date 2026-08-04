#include <globaldefs.h>

extern "C" void* _Z18GetBg0CharBaseAddrv(void);
extern "C" void* _Z18GetBg1CharBaseAddrv(void);
extern "C" void* _Z18GetBg2CharBaseAddrv(void);
extern "C" void* _Z18GetBg3CharBaseAddrv(void);
extern "C" void* _Z21GetSubBg0CharBaseAddrv(void);
extern "C" void* _Z21GetSubBg1CharBaseAddrv(void);
extern "C" void* _Z21GetSubBg2CharBaseAddrv(void);
extern "C" void* _Z21GetSubBg3CharBaseAddrv(void);

struct KindHolder020e12c0 { char pad0[8]; unsigned char kind; };

// USA: func_020e12c0  (semantic: GetCharBaseAddrByKind_020e12c0)
extern "C" ARM void* func_020e12c0(KindHolder020e12c0* obj) {
    void* result = 0;
    switch (obj->kind) {
    case 1: result = _Z18GetBg0CharBaseAddrv(); break;
    case 2: result = _Z18GetBg1CharBaseAddrv(); break;
    case 3: result = _Z18GetBg2CharBaseAddrv(); break;
    case 4: result = _Z18GetBg3CharBaseAddrv(); break;
    case 5: result = (void*)0x6400000; break;
    case 6: result = _Z21GetSubBg0CharBaseAddrv(); break;
    case 7: result = _Z21GetSubBg1CharBaseAddrv(); break;
    case 8: result = _Z21GetSubBg2CharBaseAddrv(); break;
    case 9: result = _Z21GetSubBg3CharBaseAddrv(); break;
    case 10: result = (void*)0x6600000; break;
    }
    return result;
}
