#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_020696bc(int a, int* out, int c);
extern "C" int _Z26GetGlobalField0x1c020421a0v();

struct RingBuffer020457e8 {
    char unk0[0x186c];
    int slots[4];
    char unk187c[0x131];
    signed char cursor;
};
extern "C" void _Z24PushToRingBuffer020457e8P18RingBuffer020457e8i(struct RingBuffer020457e8* rb, int value);

struct Struct02069834 { void* ptr; };

// KEEP-NAME
// USA: func_02069834
extern "C" ARM int _Z26StoreInputEmitFF1A02069834P14Struct02069834i(Struct02069834* obj, int input) {
    int val;
    unsigned short buf;
    void* dst;
    func_020696bc(input, &val, 1);
    _Z24PushToRingBuffer020457e8P18RingBuffer020457e8i((struct RingBuffer020457e8*)_Z26GetGlobalField0x1c020421a0v(), val);
    dst = obj->ptr;
    buf = 0xff1a;
    memcpy(dst, &buf, 2);
    return 2;
}
