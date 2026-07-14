#include <globaldefs.h>

void ShiftInBitOnGlobalObject(void);
void HalveGlobalObjectCounter(void);

extern "C" int func_020e0574(void* a, int* b, int c, int d);
extern "C" int func_020e046c(int a, int b, int c, int d);

// USA: func_020e04f4
ARM int ComputeAndApplyWithCounter020e04f4(int p0, void* p1, int p2, int p3, unsigned char p4, int p5) {
    int tmp;
    int result;
    int r0result;

    if (p0 == 0 || p1 == NULL || p2 < 0) {
        return 0;
    }
    if (p4 != 0) {
        ShiftInBitOnGlobalObject();
    }
    r0result = func_020e0574(p1, &tmp, p3, p5);
    result = func_020e046c(p0, r0result, tmp, p2);
    if (p4 != 0) {
        HalveGlobalObjectCounter();
    }
    return result;
}
