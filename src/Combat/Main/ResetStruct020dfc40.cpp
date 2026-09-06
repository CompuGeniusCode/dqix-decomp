#include <globaldefs.h>
#include "std_library_functions.h"

struct Obj020dfe88;
int ResetHandleState020dfe88(struct Obj020dfe88*);

struct Struct020dfc40 {
    unsigned char pad[0xc];
    short field_c;
    int field_10;
};

// USA: func_020dfc40
ARM void ResetStruct020dfc40(Struct020dfc40* p) {
    memset(p, 0, 0xc);
    p->field_c = -1;
    p->field_10 = -1;
    ResetHandleState020dfe88((struct Obj020dfe88*)p);
}
