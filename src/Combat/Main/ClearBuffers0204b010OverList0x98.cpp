#include <globaldefs.h>

struct Obj0204b010 { char b[0x20]; };
void ClearBuffer0204b010(Obj0204b010*, void*);

struct Cont0205d1e0 {
    char pad0[0x98];
    Obj0204b010* list98;
    char pad9c[0x16];
    unsigned char countB2;
};

// USA: func_0205d1e0
ARM void ClearBuffers0204b010OverList0x98(Cont0205d1e0* obj) {
    unsigned char i;
    if (obj->list98 == NULL) return;
    for (i = 0; i < obj->countB2; i++) {
        ClearBuffer0204b010(&obj->list98[i], NULL);
    }
}
