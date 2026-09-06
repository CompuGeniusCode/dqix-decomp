#include <globaldefs.h>

extern "C" void func_ov031_02239368(int val);
ARM void SetField54IfTagNot9Or10(int v);
extern "C" int func_020d5d34(int, int, int, int, int);
ARM int InvokeMaskAndSetField54_022398e8(void);

typedef void (*NotifyFn022397bc)(int, void*);

struct Inner022397bc { unsigned char pad[0x40]; int field40; int field44; };
struct Global022397bc { void* volatile fn; Inner022397bc* inner; };
extern Global022397bc data_ov031_02290d18;
extern int data_ov031_0224c3c4;
extern int data_ov031_0224c3a4;

struct Param022397bc { unsigned char pad0[2]; unsigned short field2; unsigned short field4; };

// USA: func_ov031_022397bc
extern "C" ARM void func_ov031_022397bc(Param022397bc* p) {
    if (p->field2 != 0) {
        SetField54IfTagNot9Or10(p->field2);
        func_ov031_02239368(9);
        return;
    }
    switch (p->field4) {
    case 0xa:
        if (data_ov031_02290d18.inner->field44 == 2) {
            if (data_ov031_02290d18.inner->field40 == 4) {
                if (InvokeMaskAndSetField54_022398e8() != 0) return;
                void* fn = data_ov031_02290d18.fn;
                if (fn != 0) {
                    ((NotifyFn022397bc)fn)(0x8000000, &data_ov031_0224c3c4);
                }
                func_ov031_02239368(9);
                return;
            }
            if (data_ov031_02290d18.inner->field40 == 6) {
                return;
            }
            goto ret4;
        }
        if (data_ov031_02290d18.inner->field44 == 4) {
            int r = func_020d5d34((int)((char*)data_ov031_02290d18.inner + 0x3e0 + 0x1000), 0xd, 7, 0x44, 1);
            if (r != 0) {
                SetField54IfTagNot9Or10(r);
                func_ov031_02239368(9);
                return;
            }
            func_ov031_02239368(5);
            return;
        }
    ret4:
        func_ov031_02239368(4);
        return;
    case 0xb:
        return;
    case 0xc:
    case 0xd:
    default: {
        void* fn = data_ov031_02290d18.fn;
        if (fn != 0) {
            ((NotifyFn022397bc)fn)(0x8000000, &data_ov031_0224c3a4);
        }
        return;
    }
    }
}
