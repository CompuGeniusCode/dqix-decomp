#include <globaldefs.h>

extern "C" int func_02003ce8(int, int);

struct Struct020e4798 {
    int field0;
    int field4;
};

// USA: func_020e4798
ARM int AddResultIfField4Set020e4798(int a, struct Struct020e4798* b) {
    if (b->field4 != 0) {
        return a + func_02003ce8(a, b->field4);
    }
    return a;
}
