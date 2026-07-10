#include <globaldefs.h>

struct Obj0201b600;
struct Elem0201b600;
struct Struct02013380;

Elem0201b600* FindElemByKeys(Obj0201b600* obj, int key1, unsigned short key2);
void SetFlag0x40AndToggle0x4(Struct02013380* obj, int unused, int clear4);

// USA: func_0201bd04
ARM void LookupElemAndClearFlag4(Obj0201b600* obj, int id, int index) {
    Elem0201b600* e = FindElemByKeys(obj, index, id);
    int val = 0;
    if (index >= 0) val = index & 0xff;
    if (e != NULL) {
        SetFlag0x40AndToggle0x4((Struct02013380*)e, val, 1);
    }
}
