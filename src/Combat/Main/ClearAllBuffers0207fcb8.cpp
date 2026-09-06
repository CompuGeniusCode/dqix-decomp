#include <globaldefs.h>

struct Obj0204b010;

extern void ClearBuffer0204b010(struct Obj0204b010* obj, void* p);

struct Obj0207fcb8 {
    char pad0[0x2c];
    char* entries;
    char pad30[8];
    unsigned char count;
};

// USA: func_0207fcb8
ARM void ClearAllBuffers0207fcb8(struct Obj0207fcb8* obj) {
    unsigned char i;
    if (obj->entries != NULL) {
        for (i = 0; i < obj->count; i++) {
            ClearBuffer0204b010((struct Obj0204b010*)(obj->entries + i * 0x20), NULL);
        }
    }
}
