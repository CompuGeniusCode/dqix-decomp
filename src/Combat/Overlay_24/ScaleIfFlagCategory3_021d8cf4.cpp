#include <globaldefs.h>

extern "C" int func_ov000_02156068(int, int, int, int);

// USA: func_ov024_021d8cf4
ARM int ScaleIfFlagCategory3_021d8cf4(void* a, int b, int c, int d, int e, int val) {
    if (!func_ov000_02156068(*(int*)a, (short)c, 3, 0)) {
        return val;
    }
    return (int)((float)val * 1.5f);
}
