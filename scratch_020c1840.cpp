#include <globaldefs.h>

struct Mtx33Padded_020c1840 { int m[10]; };

// USA: func_020c1840
ARM void SetIdentityMatrix33Padded_020c1840(Mtx33Padded_020c1840* m) {
    m->m[0] = 0x1000;
    m->m[1] = 0;
    m->m[2] = 0;
    m->m[3] = 0;
    m->m[4] = 0x1000;
    m->m[5] = 0;
    m->m[6] = 0;
    m->m[7] = 0;
    m->m[8] = 0x1000;
    m->m[9] = 0;
}
