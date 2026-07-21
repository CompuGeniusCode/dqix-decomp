#include <globaldefs.h>

struct Struct0223c2d0 {
    unsigned char pad0[4];
    short field4;
    unsigned short field6;
    unsigned char field8;
    unsigned char field9;
};

extern void* data_ov031_02290d34;
void* CallWithZeroExtra_0223e218(void*, void*, void*, int);
void IncrementCounterAndMaybeFire_0223c2d0(void*, Struct0223c2d0*);

// USA: func_ov031_0223c278  (semantic: InitTimerAndSchedule_0223c278)
extern "C" ARM int func_ov031_0223c278(int arg) {
    Struct0223c2d0* s = (Struct0223c2d0*)data_ov031_02290d34;
    if (s->field9 != 0) return 0;
    void* result = CallWithZeroExtra_0223e218((void*)1, (void*)IncrementCounterAndMaybeFire_0223c2d0, s, 0xc8);
    *(void**)s = result;
    s->field4 = 0;
    s->field6 = (unsigned short)arg;
    s->field9 = 1;
    return 1;
}
