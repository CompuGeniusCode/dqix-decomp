#include <globaldefs.h>

struct Obj0201b600;
struct Elem0201b600;
struct Struct02013380 { unsigned short unk0; unsigned short flags; };

extern "C" Elem0201b600* _Z14FindElemByKeysP11Obj0201b600is(Obj0201b600* obj, int key1, unsigned short key2);
void SetFlag0x40AndToggle0x4(Struct02013380* obj, int unused, int clear4);

// USA: func_0201bd3c  (semantic: SetElemFlag4ByKeys_0201bd3c)
extern "C" ARM void func_0201bd3c(Obj0201b600* obj, unsigned int argA, int argB) {
    Elem0201b600* elem = _Z14FindElemByKeysP11Obj0201b600is(obj, argB, argA);
    int flag = 0;
    if (argB >= 0) flag = argB & 0xff;
    if (elem == 0) return;
    SetFlag0x40AndToggle0x4((Struct02013380*)elem, flag, 0);
}
