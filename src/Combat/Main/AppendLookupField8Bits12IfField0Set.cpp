#include <globaldefs.h>

extern "C" int func_020e51e4(short);
extern "C" int func_020e462c(int, int, int, int);

struct Struct020e4750 {
    int field0;
    int field4;
    unsigned int low12 : 12;
    unsigned int index : 6;
    unsigned int rest : 14;
};

// USA: func_020e4750
ARM int AppendLookupField8Bits12IfField0Set(int a, struct Struct020e4750* b) {
    if (b->field0 != 0) {
        int s = func_020e51e4(b->index);
        a = func_020e462c(a, s, b->field0, 0);
    }
    return a;
}
