#include <globaldefs.h>

struct Obj0205b674 { int field0; int field4; };

int FormatAbsIntToString02042658(void* obj, int value);
extern "C" void __clear(void* buf, int n);
extern "C" int sprintf(void* dst, void* fmt, int val);
extern "C" void func_0205b234(struct Obj0205b674* a, int b, int c, void* buf, int d, int e);
extern char data_020f0518;

// USA: func_0205b674
ARM void PositionAndFormatValueLabel0205b674(struct Obj0205b674* obj, short posX, int param2, int param3,
                                              unsigned char param4, unsigned char param5, unsigned char param6, unsigned char param7) {
    if (obj->field0 != 0 && obj->field4 != 0) {
        int value = param3;
        while ((value = value / 10) != 0) {}
        int r0val = FormatAbsIntToString02042658((void*)param7, param3);
        if (param6 == 1) {
            posX = (short)(posX + (short)((param5 << 3) - r0val));
        }
        char buf[0xa];
        __clear(buf, 0xa);
        sprintf(buf, &data_020f0518, param3);
        func_0205b234(obj, posX, param2, buf, param4, param7);
    }
}
