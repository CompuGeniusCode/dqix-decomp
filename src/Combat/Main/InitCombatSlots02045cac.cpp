#include <globaldefs.h>

struct State0204166c;
void Forward020416c0(struct State0204166c* s);

struct Foo0207df50;
void CopyInternalFields0207df50(struct Foo0207df50* p);

struct CombatSlots02045cac {
    char pad0[0x9b4];
    int field9b4;
    unsigned char stateArr[0xe00];
    unsigned char byteArr[0x80];
    char pad1838[0x19b0 - 0x1838];
    unsigned char flagByte;
    char pad19b1[0x1e28 - 0x19b1];
    void* ptrField;
};

// USA: func_02045cac
ARM void InitCombatSlots02045cac(struct CombatSlots02045cac* obj) {
    obj->flagByte = 1;
    obj->field9b4 = 0;
    for (int i = 0; i < 0x80; i++) {
        Forward020416c0((struct State0204166c*)(obj->stateArr + i * 0x1c));
        obj->byteArr[i] = 0;
    }
    if (obj->ptrField != NULL) {
        CopyInternalFields0207df50((struct Foo0207df50*)obj->ptrField);
    }
}
