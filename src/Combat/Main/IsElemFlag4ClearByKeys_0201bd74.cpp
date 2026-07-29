#include <globaldefs.h>

struct Obj0201b600;
struct Elem0201b600;
struct Struct02013380 { unsigned short unk0; unsigned short flags; };

extern "C" Elem0201b600* _Z14FindElemByKeysP11Obj0201b600is(Obj0201b600* obj, int key1, unsigned short key2);

// USA: func_0201bd74  (semantic: IsElemFlag4ClearByKeys_0201bd74)
extern "C" ARM int func_0201bd74(Obj0201b600* obj, unsigned int argA, int argB) {
    Elem0201b600* elem = _Z14FindElemByKeysP11Obj0201b600is(obj, argB, argA);
    if (elem != 0) {
        return (((Struct02013380*)elem)->flags & 4) == 0;
    }
    return 0;
}
