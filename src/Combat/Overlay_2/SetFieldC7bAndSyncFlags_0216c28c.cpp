#include <globaldefs.h>

extern "C" void func_ov017_0218b5c0(int set, int bit);
extern "C" void func_ov017_0218b5f8(int bit);

// USA: func_ov002_0216c28c  (semantic: SetFieldC7bAndSyncFlags_0216c28c)
extern "C" ARM void func_ov002_0216c28c(void* obj, int val) {
    int masked = val & 0xff;
    *((unsigned char*)obj + 0x1000 + 0xc7b) = val;
    if (masked != 0xb && masked != 0xc) return;
    {
        func_ov017_0218b5c0(1, *((signed char*)obj + 0x1c00 + 0x20));
        func_ov017_0218b5c0(1, *((signed char*)obj + 0x1c00 + 0x21));
        func_ov017_0218b5f8(-1);
    }
}
