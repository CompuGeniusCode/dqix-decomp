#include <globaldefs.h>

extern "C" int func_0202df58(void);

// USA: func_0202c540
ARM int IsField0AndGlobalNonZero0202c540(int* obj) {
    int a = (obj[0] != 0);
    int r;
    if (a) {
        r = (func_0202df58() != 0);
    } else {
        r = 0;
    }
    return r;
}
