#include <globaldefs.h>

extern "C" int func_02003ce8(int, int);

struct Struct020e46d8 {
    int field0;
    int field4;
};

// USA: func_020e46d8
ARM int AddResultIfField0Set020e46d8(int a, struct Struct020e46d8* b) {
    if (b->field0 != 0) {
        return a + func_02003ce8(a, b->field0);
    }
    return a;
}
