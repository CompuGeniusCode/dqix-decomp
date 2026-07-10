#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_0203b19c(int base, int a, int b);
extern "C" void func_02022bb0(void* obj);

struct Obj02022d78 {
    char pad[0x9c1];
    unsigned char curValue;   // 0x9c1
    unsigned char field9c2;   // 0x9c2
    unsigned char activeFlag; // 0x9c3
    char pad2[0xa34 - 0x9c4];
    unsigned char prevValue;  // 0xa34
};

// USA: func_02022d78
ARM void SetActiveModeSavingPrevious02022d78(struct Obj02022d78* obj, int newValue) {
    if (obj->activeFlag != 0) {
        func_0203b19c(func_ov017_0218b5b0(), -16, 0);
    }
    func_02022bb0(obj);
    obj->prevValue = obj->curValue;
    obj->curValue = newValue;
    obj->activeFlag = 1;
    obj->field9c2 = 0;
}
