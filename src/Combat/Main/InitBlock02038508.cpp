#include <globaldefs.h>

struct Vec3Block02038508 { int v[3]; };

struct SubBlock02038508 {
    unsigned char a, b, c, d;   // 0x0-0x3
    unsigned short e;           // 0x4
    short f, g, h;              // 0x6, 0x8, 0xa
    struct Vec3Block02038508 v0; // 0xc
    struct Vec3Block02038508 v1; // 0x18
    struct Vec3Block02038508 v2; // 0x24
    struct Vec3Block02038508 v3; // 0x30
    struct Vec3Block02038508 v4; // 0x3c
    int field48;                // 0x48
    int field4c;                // 0x4c
    short field50;              // 0x50
    unsigned char field52;      // 0x52
    unsigned char field53;      // 0x53
    unsigned char field54;      // 0x54
    int field58;                // 0x58
    int field5c;                // 0x5c
    int field60;                // 0x60
};

// USA: func_02038508
ARM void InitBlock02038508(struct SubBlock02038508* p) {
    p->a = 0;
    p->b = 0;
    p->c = 0;
    p->d = 0;
    p->e = 0;
    p->f = 0;
    p->g = 0;
    p->h = 0;
    p->field48 = 0;
    p->field4c = 0;
    p->field50 = 0;
    p->field52 = 0;
    p->field53 = 1;
    p->field54 = 0x64;
    p->field58 = 0;
    p->field5c = 0;
    p->field60 = 0;
    p->v0.v[0] = 0; p->v0.v[1] = 0; p->v0.v[2] = 0;
    p->v1.v[0] = 0; p->v1.v[1] = 0; p->v1.v[2] = 0;
    p->v2.v[0] = 0; p->v2.v[1] = 0; p->v2.v[2] = 0;
    p->v3.v[0] = 0; p->v3.v[1] = 0; p->v3.v[2] = 0;
    p->v4.v[0] = 0; p->v4.v[1] = 0; p->v4.v[2] = 0;
}
