#include <globaldefs.h>

struct B174Inner {
    unsigned short flag;
};

struct B174Outer {
    char unk[4];
    struct B174Inner* inner;
};

// USA: func_0205b174
ARM int GetBits10And11(int unused, struct B174Outer* obj) {
    if (obj == 0) {
        return 0;
    }
    return ((unsigned int)obj->inner->flag >> 10) & 3;
}
