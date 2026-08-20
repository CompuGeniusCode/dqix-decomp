#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#pragma opt_propagation off

extern "C" void* _Z27GetDataPtr02114e04_020d6c00v(void);
extern "C" int _Z17TestFlags02046708P16FlagWord02046708j(struct FlagWord02046708* word, unsigned int mask);
int GetField0x3b0Value(struct BattleStruct* battleStruct);

struct Vec3copy0202ec84 { int x; int y; int z; };
extern "C" ARM int _Z27ComputeTwoFromVec3_0202ec84PvP16Vec3copy0202ec84PiS2_(void* obj, struct Vec3copy0202ec84* src, int* out1, int* out2);

struct StructAt020473c8;
ARM void RenderFlaggedIndexedEntry(struct StructAt020473c8* obj, int param1);

struct Node0205337c {
    unsigned char pad0[0x1c];
    int screenX; // 0x1c
    int screenY; // 0x20
    int depth;   // 0x24
};

struct Obj0205337c {
    unsigned char pad0[0x44];
    struct Vec3copy0202ec84 pose; // 0x44
    unsigned char pad1[0x178 - 0x50];
    signed char anim[5];          // 0x178
    signed char animIdx;          // 0x17d
    unsigned char pad2[0x190 - 0x17e];
    struct Node0205337c* node;    // 0x190
};

inline signed char* GetAnimTable_0205337c(struct Obj0205337c* obj) {
    return (signed char*)((char*)obj + 0x178);
}

// USA: func_0205337c
extern "C" ARM void func_0205337c(struct Obj0205337c* obj) {
    if (_Z17TestFlags02046708P16FlagWord02046708j((struct FlagWord02046708*)_Z27GetDataPtr02114e04_020d6c00v(), 2)) return;
    if (obj->node == NULL) return;

    void* target = (void*)GetField0x3b0Value(GetBattleStruct());
    *(volatile int*)0x4000444 = 0;

    struct Vec3copy0202ec84 pose = obj->pose;
    pose.y += 0x1b33;

    int outB, outA;
    _Z27ComputeTwoFromVec3_0202ec84PvP16Vec3copy0202ec84PiS2_(target, &pose, &outB, &outA);
    outB -= 0xc;
    outA -= 0xc;

    int idx = obj->animIdx;
    int kind = GetAnimTable_0205337c(obj)[idx];
    if (!(kind != 0xc && kind != 0xd && kind != 0xe)) {
        outB -= 0xc;
        outA -= 6;
    } else if (kind == 0x1e) {
        outA += 4;
        outB += 4;
    }

    int sx = outB;
    int sy = outA;
    struct Node0205337c* node = obj->node;
    node->screenX = sx << 12;
    node->screenY = sy << 12;
    node->depth = -0xa000;

    RenderFlaggedIndexedEntry((struct StructAt020473c8*)obj->node, 1);
    *(volatile int*)0x4000448 = 1;
}
