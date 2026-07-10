#include <globaldefs.h>

extern "C" int func_020e51e4(short);
extern "C" int func_020e462c(int, int, int, int);

struct Struct020e46fc {
    int field0;
    int field4;
    unsigned int index : 6;
    unsigned int rest : 26;
};

// USA: func_020e46fc
ARM int AppendLookupField8Low6Plus100IfField0Set(int a, struct Struct020e46fc* b) {
    if (b->field0 != 0) {
        int s = func_020e51e4((short)(b->index + 0x64));
        a = func_020e462c(a, s, b->field0, 0);
    }
    return a;
}
