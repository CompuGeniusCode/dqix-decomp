#include <globaldefs.h>

extern "C" int func_020ce56c(int a, int b, void* out);

#pragma optimize_for_size off
// USA: func_020cee18
ARM int FetchHalfword0xF6(int* out) {
    unsigned short v;
    int result = func_020ce56c(0xf, 6, &v);
    if (result != 0) {
        return result;
    }
    if (out != NULL) {
        *out = v;
    }
    return result;
}
