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

struct Obj02097b34 {
    unsigned int field0;
    int field4;
    int field8;
    int fieldc;
    int field10;
    int field14;
    char pad18[0x1e - 0x18];
    unsigned char field1e;
};

// USA: func_02097b34
extern "C" ARM void func_02097b34(struct Obj02097b34* obj) {
    PushOneBitField0x3c();
    if (obj->field1e & 1) {
        unsigned int mask;
        unsigned short count;

        func_020c40f0(obj->field0);
        SetVramFieldAndDispatch020c42c8(obj->field4);
        func_020c3b64(obj->field8);
        SetVramBankAndDispatch020c3df4(obj->fieldc);

        mask = obj->field0;
        count = 0;
        while (mask != 0) {
            count = count + 1;
            mask &= mask - 1;
        }
        ConfigurePairMode020bb48c(count, 1);
    }
    if (obj->field1e & 2) {
        func_020c45b0(obj->field10);
        _Z31SetVramFieldAndDispatch020c4658t(obj->field14);
    }
    ForwardToItcm01ff9098();
    HalveField0x3c020dc098();
}
