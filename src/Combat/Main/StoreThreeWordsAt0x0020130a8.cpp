#include <globaldefs.h>

// USA: func_020130a8
ARM void StoreThreeWordsAt0x0020130a8(int* obj, int a, int b, int c) {
    obj[0] = a;
    obj[1] = b;
    obj[2] = c;
}
