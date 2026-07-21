#include <globaldefs.h>

void SetField164_02203164(int v);
void CopyField164_02203270(void* obj);
void InitSessionFields_0220321c(void);
void ResetSessionState02203190(void);
void SetField38IfPresent_02203288(int value);
extern "C" void func_ov031_0220603c(void);

struct Inner022053a0 {
    unsigned char pad0[0x68];
    int field68;
    unsigned char pad1[4];
    short field70;
    unsigned char pad2[1];
    signed char field73;
};

struct Outer022053a0 {
    unsigned char pad0[4];
    Inner022053a0* field4;
};

// USA: func_ov031_022053a0
extern "C" ARM int func_ov031_022053a0(Outer022053a0* param) {
    Inner022053a0* obj = param->field4;
    SetField164_02203164((int)obj);
    signed char selector = obj->field73;
    int extra = obj->field68;

    switch (selector) {
    case 0:
    case 4:
        CopyField164_02203270((void*)(extra + 0x20));
        InitSessionFields_0220321c();
        break;
    case 1:
        InitSessionFields_0220321c();
        ResetSessionState02203190();
        SetField38IfPresent_02203288((int)func_ov031_0220603c);
        break;
    case 2:
        ResetSessionState02203190();
        break;
    default:
        break;
    }

    obj->field70 = 1;
    return 0;
}
