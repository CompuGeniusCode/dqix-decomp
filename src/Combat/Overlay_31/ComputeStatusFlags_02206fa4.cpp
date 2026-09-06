#include <globaldefs.h>

int IsNotInList0224e22c_02207180(void* v);
unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);
struct Obj02207074;
int GetProgress_02207074(Obj02207074* obj);
extern "C" int func_ov031_022063ec(void* obj);

struct Obj02206fa4 {
    char pad0[8];
    unsigned char field8;
    char pad1[0x70 - 9];
    volatile short field70;
    char pad2;
    signed char field73;
};

// USA: func_ov031_02206fa4  (semantic: ComputeStatusFlags_02206fa4)
extern "C" ARM int func_ov031_02206fa4(Obj02206fa4* obj) {
    int flags = 0;
    if (IsNotInList0224e22c_02207180(obj)) {
        flags |= 0x80;
        goto end;
    }

    if (obj->field70 & 0x40) flags |= 0x20;
    signed char f73 = obj->field73;
    if (f73 == 1 || (obj->field70 & 4)) {
        unsigned int status = DisableIRQInterrupts();
        if (GetProgress_02207074((Obj02207074*)obj) > 0) flags |= 1;
        if (func_ov031_022063ec(obj) > 0) flags |= 8;
        SetIRQInterruptState(status);
    }

    {
        signed char f73b = obj->field73;
        int isTerminal = 1;
        if (f73b != 0 && f73b != 4) isTerminal = 0;
        if (!isTerminal) goto end;
    }

    if ((obj->field70 & 4) && (obj->field8 != 4)) {
        if (!(flags & 1)) {
            obj->field70 = obj->field70 & ~6;
        }
    }

    if (obj->field70 & 2) goto end;
    if (!(obj->field70 & 4)) flags |= 0x40;
end:
    return flags;
}
