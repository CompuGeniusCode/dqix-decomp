#include <globaldefs.h>

struct Quad020c111c { int a; int b; int c; int d; };

// USA: func_020c111c
THUMB void SetQuadFromPair_020c111c(Quad020c111c* obj, int b, int c) {
    obj->a = c;
    obj->b = b;
    obj->c = -b;
    obj->d = c;
}
