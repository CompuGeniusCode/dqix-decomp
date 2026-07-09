#include <globaldefs.h>
struct Block0207df50 { unsigned int v[10]; };
struct Pair0207df50 { unsigned int v[2]; };
struct Foo0207df50 {
    struct Block0207df50 a;   // 0x00
    struct Block0207df50 b;   // 0x28
    unsigned int c;           // 0x50
    unsigned int d;           // 0x54
    struct Pair0207df50 p1;   // 0x58
    struct Pair0207df50 p2;   // 0x60
};
// USA: func_0207df50
ARM void CopyInternalFields0207df50(struct Foo0207df50 *p) {
    p->b = p->a;
    p->p2 = p->p1;
}
