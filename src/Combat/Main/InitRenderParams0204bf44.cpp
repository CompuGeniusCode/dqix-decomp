#include <globaldefs.h>

struct RenderSource0204bf44 {
    int type;         // 0x0
    int shift;        // 0x4
    short s8;         // 0x8
    short sa;         // 0xa
    short sc;         // 0xc
    short se;         // 0xe
    short s10;        // 0x10
    short s12;        // 0x12
    int pad14;        // 0x14
    int pad18;        // 0x18
    int m1c;          // 0x1c
    unsigned int m20; // 0x20
    int o24;          // 0x24
    int o28;          // 0x28
    int o2c;          // 0x2c
    int o30;          // 0x30
    int pad34;        // 0x34
    int o38;          // 0x38
};

struct RenderParams0204bf44 {
    struct RenderSource0204bf44 *src; // 0x0
    char *p4;         // 0x4
    char *p8;         // 0x8
    char *pc;         // 0xc
    char *p10;        // 0x10
    char *p14;        // 0x14
    int d18;          // 0x18
    int d1c;          // 0x1c
    int d20;          // 0x20
    int d24;          // 0x24
    int d28;          // 0x28
    int d2c;          // 0x2c
    int pad30[6];     // 0x30..0x47
    int d48;          // 0x48
};

// USA: func_0204bf44
ARM void InitRenderParams0204bf44(struct RenderParams0204bf44 *d, int arg1, struct RenderSource0204bf44 *s) {
    d->src = s;
    d->p4 = (char*)s + d->src->o24;
    d->p8 = (char*)s + d->src->o28;
    d->pc = (char*)s + d->src->o2c;
    d->p10 = (char*)s + d->src->o30;
    if (d->src->type == 3) {
        d->p14 = (char*)s + d->src->o38;
    }
    d->d24 = d->src->s8 << d->src->shift;
    d->d28 = d->src->sa << d->src->shift;
    d->d2c = d->src->sc << d->src->shift;
    d->d18 = d->src->se << d->src->shift;
    d->d1c = d->src->s10 << d->src->shift;
    d->d20 = d->src->s12 << d->src->shift;
    d->d48 = d->src->m1c * d->src->m20 + (d->src->m20 >> 1);
}
