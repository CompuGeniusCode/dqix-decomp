#include <globaldefs.h>

struct Struct_0205bd58 {
    char unk0[0x34];
    int f34;
    char unk38[0x4];
    int f3c;
    int f40;
    int f44;
    int f48;
};

// USA: func_0205bd58
ARM void SetFields0205bd58(struct Struct_0205bd58* s, int a, int b, int c, int d, int e) {
    s->f34 = a;
    s->f3c = b;
    s->f40 = c;
    s->f44 = d;
    s->f48 = e;
}
