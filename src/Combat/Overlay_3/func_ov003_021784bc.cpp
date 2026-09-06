#include <globaldefs.h>

struct KeyMap020a0b3c { short* keys; signed char* values; short count; };
signed char LookupValueByKey020a0b3c(struct KeyMap020a0b3c* map, int key);
int SumSlotsWithFlag0x1000x150_02086d20(unsigned char* p);
extern "C" int func_0207c7a0(void* p, int e, int c);

// USA: func_ov003_021784bc
extern "C" ARM int func_ov003_021784bc(void* self, int key, unsigned int kind, int d) {
    int result = 0;
    unsigned int inRange = (kind >= 8 && kind <= 9);
    if (inRange) {
        void* ptr = self;
        if (kind == 9) {
            ptr = (char*)self + 0x204 + 0xc00;
        }
        signed char val1 = LookupValueByKey020a0b3c((struct KeyMap020a0b3c*)ptr, key);
        int val2 = SumSlotsWithFlag0x1000x150_02086d20((unsigned char*)self);
        result = (d * 8 + 0x63) - (val1 + val2);
    } else {
        unsigned int lowRange = (kind <= 7);
        if (lowRange) {
            result = 0x63 - func_0207c7a0((char*)self + 0x1d4, key, 9);
        }
    }
    return result;
}
