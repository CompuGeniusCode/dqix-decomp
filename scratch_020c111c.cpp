#include <globaldefs.h>

struct Vec4Pair020c111c {
    int a;
    int b;
    int c;
    int d;
};

// USA: func_020c111c
THUMB void SetMirroredPair020c111c(Vec4Pair020c111c* obj, int a, int b) {
    obj->a = b;
    obj->b = a;
    obj->c = -a;
    obj->d = b;
}
