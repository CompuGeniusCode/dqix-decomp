#include <globaldefs.h>

struct StructF0x60_0203cdd0;
extern int GetField0x60(struct StructF0x60_0203cdd0* obj);

struct ThreeWords0x50_02040a20 { unsigned int v[3]; };

struct Struct02040a20 {
    char pad[0x14];
    void* f14;
    void* f18;
    void* f1c;
};

// USA: func_02040a20
ARM int GetOffset0x54FromFallbackChain(struct Struct02040a20* obj) {
    void* p;

    p = obj->f14;
    if (p != NULL) {
        return GetField0x60((struct StructF0x60_0203cdd0*)p);
    }

    p = obj->f18;
    if (p != NULL) {
        struct ThreeWords0x50_02040a20 t1;
        t1 = *(struct ThreeWords0x50_02040a20*)((char*)p + 0x50);
        return (int)t1.v[1];
    }

    p = obj->f1c;
    if (p != NULL) {
        struct ThreeWords0x50_02040a20 t2;
        t2 = *(struct ThreeWords0x50_02040a20*)((char*)p + 0x50);
        return (int)t2.v[1];
    }

    return 0;
}
