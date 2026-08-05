#include <globaldefs.h>

struct Vec3s32_020c3030 { int x; int y; int z; };
int Distance3D020c3030(struct Vec3s32_020c3030* a, struct Vec3s32_020c3030* b);

struct Node0x10_02028460 {
    unsigned char id;
    unsigned char pad1[3];
    short x;
    short y;
    short z;
    unsigned char pad2[6];
};

struct SearchCtx_02028460 {
    unsigned char pad0[2];
    unsigned char count;
    unsigned char pad1[1];
    struct Node0x10_02028460* nodes;
};

// USA: func_02028460  (semantic: FindClosestNodeIndex_02028460)
extern "C" ARM int func_02028460(struct SearchCtx_02028460* ctx, struct Vec3s32_020c3030* pos) {
    if (ctx->count == 0) return 0;

    struct Node0x10_02028460* nodes = ctx->nodes;
    struct Vec3s32_020c3030 v0;
    v0.x = (int)nodes[0].x << 12;
    v0.y = (int)nodes[0].y << 12;
    v0.z = (int)nodes[0].z << 12;
    int bestIdx = 0;
    int bestDist = Distance3D020c3030(pos, &v0);

    for (int i = 1; i < ctx->count; i++) {
        struct Vec3s32_020c3030 v;
        v.x = (int)nodes[i].x << 12;
        v.y = (int)nodes[i].y << 12;
        v.z = (int)nodes[i].z << 12;
        int d = Distance3D020c3030(pos, &v);
        if (d < bestDist) {
            bestIdx = i;
            bestDist = d;
        }
    }
    return bestIdx;
}
