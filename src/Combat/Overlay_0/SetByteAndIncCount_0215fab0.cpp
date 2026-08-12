#include <globaldefs.h>

struct RingBuf0215fab0 {
    unsigned char pad[0x8e44];
    unsigned char data[3];
    unsigned char count;
};

// USA: func_ov000_0215fab0  (semantic: SetByteAndIncCount_0215fab0)
extern "C" ARM void func_ov000_0215fab0(struct RingBuf0215fab0 *obj, unsigned char val) {
    unsigned char cnt = obj->count;
    if (cnt < 3) {
        obj->count = cnt + 1;
        obj->data[cnt] = val;
    }
}
