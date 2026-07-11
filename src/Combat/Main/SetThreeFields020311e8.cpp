#include <globaldefs.h>

struct S020311e8 {
    int x;
    int y;
    int z;
};

// USA: func_020311e8
ARM void SetThreeFields020311e8(struct S020311e8* obj, int a, int b, int c) {
    obj->x = a;
    obj->y = b;
    obj->z = c;
}
