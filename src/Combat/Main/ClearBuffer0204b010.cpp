#include <globaldefs.h>
#include "std_library_functions.h"

extern unsigned int data_020e7b98[][4];

struct Obj0204b010 {
    char pad0[0x14];
    void* field14;
    unsigned int field18;
    char pad1c[3];
    unsigned char byte1f;
};

// USA: func_0204b010
ARM void ClearBuffer0204b010(Obj0204b010* obj, void* p) {
    if (p == NULL) p = obj->field14;
    if (p == NULL) return;
    memset(p, 0, data_020e7b98[obj->byte1f][obj->field18]);
}
