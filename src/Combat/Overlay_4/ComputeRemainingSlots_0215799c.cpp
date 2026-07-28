#include <globaldefs.h>

struct KeyMap020a0b3c { short* keys; signed char* values; short count; };
signed char LookupValueByKey020a0b3c(struct KeyMap020a0b3c* map, int key);
int SumSlotsWithFlag0x1000x150_02086d20(unsigned char* p);
extern "C" int func_0207c7a0(void* p, int e, int c);

// USA: func_ov004_0215799c  (semantic: ComputeRemainingSlots_0215799c)
extern "C" ARM int func_ov004_0215799c(void* a, int e, unsigned int kind, int d) {
    int result = 0;
    unsigned int flag = (kind >= 8 && kind <= 9);
    if (flag) {
        void* ptr = a;
        if (kind == 9) {
            ptr = (char*)a + 0x204 + 0xc00;
        }
        signed char val1 = LookupValueByKey020a0b3c((struct KeyMap020a0b3c*)ptr, e);
        int val2 = SumSlotsWithFlag0x1000x150_02086d20((unsigned char*)a);
        result = (d * 8 + 0x63) - (val1 + val2);
    } else {
        unsigned int flag2 = (kind <= 7);
        if (flag2) {
            result = 0x63 - func_0207c7a0((char*)a + 0x1d4, e, 9);
        }
    }
    return result;
}
