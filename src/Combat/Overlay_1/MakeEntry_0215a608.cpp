#include <globaldefs.h>
#include "std_library_functions.h"

struct Obj0215a608 { int type; int f1, f2, f3; int field16; };

extern "C" struct Obj0215a608* func_ov001_02159fd4(void);

// USA: func_ov001_0215a608
ARM int MakeEntry_0215a608(int unused, int a1, int a2, int a3, int count) {
    struct Obj0215a608* obj = func_ov001_02159fd4();
    if (obj == NULL) return (int)obj;
    if (count <= 0) {
        obj->type = 0x10;
    } else {
        obj->type = 0x11;
    }
    memcpy(&obj->f1, &a1, 0xc);
    obj->field16 = count;
    return count;
}
