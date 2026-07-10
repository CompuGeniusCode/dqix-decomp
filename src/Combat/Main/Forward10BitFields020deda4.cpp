#include <globaldefs.h>

extern "C" int func_020ded1c(int, int, int, int);

struct Fields020deda4 {
    unsigned char pad0[0x10];
    unsigned int lo10 : 10;
    unsigned int mid10 : 10;
    unsigned int rest : 12;
};

// USA: func_020deda4
ARM int Forward10BitFields020deda4(int a, int b, struct Fields020deda4* c) {
    if (c != NULL) {
        return func_020ded1c(a, b, c->lo10, c->mid10);
    }
    return 0;
}
