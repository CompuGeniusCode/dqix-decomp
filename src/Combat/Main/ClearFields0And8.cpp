#include <globaldefs.h>

struct ClearFields0And8Struct { unsigned int a; unsigned int b; unsigned int c; };

// USA: func_020c8ee8
ARM void ClearFields0And8(struct ClearFields0And8Struct* p) {
    p->a = 0;
    p->c = 0;
}
