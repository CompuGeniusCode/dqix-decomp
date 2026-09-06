#include <globaldefs.h>

struct Result020b1020 { int a; int b; };

extern "C" int func_020b0f00(void* obj, int param2, int count, int* countOut);

// USA: func_020b1020
ARM Result020b1020 Compute020b1020(void* iface, int param2, int adjustment, int count) {
    Result020b1020 result;
    int* zeroPtr = (int*)&result;
    zeroPtr[0] = 0;
    zeroPtr[1] = 0;
    int n = 1;
    if (count != 0) {
        do {
            int r = func_020b0f00(iface, param2, count, &count);
            if (r > result.a) {
                result.a = r;
            }
            n++;
        } while (count != 0);
    }
    signed char b = ((signed char*)(*(void**)iface))[1];
    result.b = (n - 1) * (adjustment + b) - adjustment;
    return result;
}
