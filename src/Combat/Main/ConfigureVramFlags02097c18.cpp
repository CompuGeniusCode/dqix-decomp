#include <globaldefs.h>

void PushOneBitField0x3c();
extern "C" void func_020c40f0(int handle);
void SetVramFieldAndDispatch020c42c8(int value);
extern "C" void func_020c3b64(int v);
void SetVramBankAndDispatch020c3df4(int mode);
ARM void ConfigurePairMode020bb48c(unsigned int mode, int installHandlers);
extern "C" void func_020c45b0(int);
extern "C" void _Z31SetVramFieldAndDispatch020c4658t(int value);
void ForwardToItcm01ff9098(void);
void HalveField0x3c020dc098(void);

struct Obj02097c18 {
    char pad[0x1e];
    unsigned char field1e;
};

// USA: func_02097c18  (semantic: ConfigureVramFlags02097c18)
extern "C" ARM void func_02097c18(struct Obj02097c18* obj, unsigned char flags, unsigned int field0Val, int field4Val, int field8Val, int fieldcVal, int field10Val, int field14Val) {
    PushOneBitField0x3c();
    obj->field1e = flags;
    if (flags & 1) {
        unsigned int mask;
        unsigned short count;

        func_020c40f0(field0Val);
        SetVramFieldAndDispatch020c42c8(field4Val);
        func_020c3b64(field8Val);
        SetVramBankAndDispatch020c3df4(fieldcVal);

        mask = field0Val;
        count = 0;
        while (mask != 0) {
            count = count + 1;
            mask &= mask - 1;
        }
        ConfigurePairMode020bb48c(count, 1);
    }
    if (flags & 2) {
        func_020c45b0(field10Val);
        _Z31SetVramFieldAndDispatch020c4658t(field14Val);
    }
    ForwardToItcm01ff9098();
    HalveField0x3c020dc098();
}
