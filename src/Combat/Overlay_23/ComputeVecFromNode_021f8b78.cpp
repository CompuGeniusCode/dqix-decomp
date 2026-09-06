#include <globaldefs.h>

struct Vec3_021f8b78 { int x; int y; int z; };

class VNode021f8b78 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual Vec3_021f8b78 MethodAt20();
};

struct Obj021f8b78Src {
    char pad0[0x34];
    unsigned short f34;
    char pad35[0x3a - 0x36];
    unsigned short f3a;
    unsigned short f3c;
};

extern "C" void __clear(void* buf, int n);
extern "C" void* func_ov011_021849c8(void* p);
extern "C" VNode021f8b78* func_ov023_021f6880(void* base, int key);

// USA: func_ov023_021f8b78  (semantic: ComputeVecFromNode_021f8b78)
extern "C" ARM Vec3_021f8b78 func_ov023_021f8b78(struct Obj021f8b78Src* src, void* arg2) {
    Vec3_021f8b78 local;
    __clear(&local, 0xc);
    local.x = src->f3a << 12;
    local.y = src->f3c << 12;

    void* base = func_ov011_021849c8(arg2);
    VNode021f8b78* node = func_ov023_021f6880(base, src->f34);
    if (node != NULL) {
        Vec3_021f8b78 v = node->MethodAt20();
        local.x = local.x + v.x;
        local.y = local.y + v.y;
    }
    return local;
}
