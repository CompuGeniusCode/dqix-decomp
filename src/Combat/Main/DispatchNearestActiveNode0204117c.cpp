#include <globaldefs.h>

extern "C" int rand(void);

struct Vec3s32_020c3030 { int x; int y; int z; };
extern int Distance3D020c3030(struct Vec3s32_020c3030* a, struct Vec3s32_020c3030* b);

struct Node020409b0 {
    char pad[0x14];
    void* f14;
    void* f18;
};
extern int DispatchOnActiveChild020409b0(struct Node020409b0* obj, int arg);

struct Node0204117c {
    int x, y, z;
    int f0xc;
    struct Node0204117c* next;
};

struct Container0204117c {
    unsigned char pad0[0x1f];
    unsigned char modeByte;
    unsigned char pad20[0x22 - 0x20];
    unsigned char countByte;
    unsigned char pad23[0x34 - 0x23];
    struct Node0204117c* listHead;
};

struct Obj0204117c {
    unsigned char pad0[0xc];
    struct Container0204117c* cont;
};

// USA: func_0204117c
ARM void DispatchNearestActiveNode0204117c(struct Obj0204117c* obj, struct Vec3s32_020c3030* refPoint) {
    struct Node0204117c* node = obj->cont->listHead;
    while (node != NULL) {
        if (node->f0xc != 0) {
            if (Distance3D020c3030((struct Vec3s32_020c3030*)node, refPoint) != 0) {
                DispatchOnActiveChild020409b0((struct Node020409b0*)obj, (int)node);
                goto epilogue;
            }
            break;
        } else {
            node = node->next;
        }
    }
    node->f0xc = 0;
    node = node->next;
    if (obj->cont->modeByte == 9) {
        int skip = rand() % obj->cont->countByte;
        int i;
        for (i = 0; i < skip; i++) {
            node = node->next;
        }
    }
    {
        struct Vec3s32_020c3030 localBuf;
        localBuf.x = node->x;
        localBuf.y = node->y;
        localBuf.z = node->z;
        node->f0xc = 1;
        DispatchOnActiveChild020409b0((struct Node020409b0*)obj, (int)&localBuf);
    }
epilogue:;
}
