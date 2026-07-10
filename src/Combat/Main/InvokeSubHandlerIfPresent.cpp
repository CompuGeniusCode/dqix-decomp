#include <globaldefs.h>

int EncodeStreamValue020dc0c8(int);

// USA: func_020e2478
ARM int InvokeSubHandlerIfPresent(int* obj) {
    int p = obj[0];
    if (p == 0) return p;
    return EncodeStreamValue020dc0c8(p);
}
