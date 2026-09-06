#include <globaldefs.h>

struct S020a13c4 {
    int a;
    short b;
    short c;
    int d;
    int e;
    char f;
};

// USA: func_020a13c4
ARM void ClearStruct020a13c4(struct S020a13c4* p) {
    p->a = 0;
    p->b = 0;
    p->c = 0;
    p->d = 0;
    p->e = 0;
    p->f = 0;
}
