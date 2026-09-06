#include <globaldefs.h>

int EnqueueEvent0x0C(int a, int b, int c, int d);
struct NodeCEE54;
struct NodeCEE68;
void PrependToGlobalList02111804(struct NodeCEE54*);
void AppendToGlobalList02111800(struct NodeCEE68*);

struct Actor020bcb70 {
    char pad0[8];       /* 0x00 */
    char node54[0xc];   /* 0x08 */
    char node68[0x10];  /* 0x14 */
    int field24;        /* 0x24 */
    char pad28[0x18];   /* 0x28 */
    int field40;        /* 0x40 */
    int field44;        /* 0x44 */
};

// USA: func_020bcb70
ARM void RegisterActorInGlobalLists020bcb70(struct Actor020bcb70* obj) {
    EnqueueEvent0x0C(obj->field44, 0, 1 << obj->field40, 0);
    if ((obj->field24 << 30) >> 31) return;
    PrependToGlobalList02111804((struct NodeCEE54*)&obj->node54);
    AppendToGlobalList02111800((struct NodeCEE68*)&obj->node68);
    obj->field24 |= 2;
}
