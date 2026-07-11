#include <globaldefs.h>

struct Foo02033b58;
void SetByteSavingPrevious(struct Foo02033b58* p, unsigned char v);
int IsValueInRange0201b5d8(int x);

extern "C" unsigned short* func_02012fe4(void);
extern "C" void func_02076ccc(void* obj, int flag);

struct Actor02076d5c { char pad[0x14c]; unsigned int field_14c; };

// USA: func_02076d5c
ARM void TriggerActorResetIfNeeded02076d5c(struct Actor02076d5c* obj) {
    if (IsValueInRange0201b5d8(*func_02012fe4()) != 0 || obj->field_14c > 0x3e8) {
        SetByteSavingPrevious((struct Foo02033b58*)obj, 0);
        func_02076ccc(obj, 1);
    }
}
