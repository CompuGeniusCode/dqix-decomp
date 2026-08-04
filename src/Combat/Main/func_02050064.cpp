#include <globaldefs.h>

extern "C" void* _Z18GetBg0CharBaseAddrv(void);
extern "C" void* _Z18GetBg1CharBaseAddrv(void);
extern "C" void* _Z18GetBg2CharBaseAddrv(void);
extern "C" void* _Z18GetBg3CharBaseAddrv(void);
extern "C" void* _Z21GetSubBg0CharBaseAddrv(void);
extern "C" void* _Z21GetSubBg1CharBaseAddrv(void);
extern "C" void* _Z21GetSubBg2CharBaseAddrv(void);
extern "C" void* _Z21GetSubBg3CharBaseAddrv(void);

struct KindHolder02050064 { char pad0[0x1c]; unsigned char sub : 4; unsigned char idx : 4; };
struct Obj02050064 { char pad0[4]; KindHolder02050064* s; };

// USA: func_02050064
extern "C" ARM void* func_02050064(Obj02050064* obj) {
    void* result = 0;
    KindHolder02050064* s = obj->s;
    if (!s->sub) {
        switch (s->idx) {
        case 0: result = _Z18GetBg0CharBaseAddrv(); break;
        case 1: result = _Z18GetBg1CharBaseAddrv(); break;
        case 2: result = _Z18GetBg2CharBaseAddrv(); break;
        case 3: result = _Z18GetBg3CharBaseAddrv(); break;
        }
    } else {
        switch (s->idx) {
        case 0: result = _Z21GetSubBg0CharBaseAddrv(); break;
        case 1: result = _Z21GetSubBg1CharBaseAddrv(); break;
        case 2: result = _Z21GetSubBg2CharBaseAddrv(); break;
        case 3: result = _Z21GetSubBg3CharBaseAddrv(); break;
        }
    }
    return result;
}
