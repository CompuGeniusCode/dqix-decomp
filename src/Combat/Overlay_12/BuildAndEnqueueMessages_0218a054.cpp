#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov012_021893b4(void *self, int flags, int a, int b);
extern "C" void func_ov012_0218a2b8(void *self, void *dst, int c);
extern "C" void func_ov012_0218a1f4(void *self, void *dst, int c);
extern "C" void func_ov012_0218a374(void *self, void *dst, int c);
extern "C" void func_0205d304(void *a, void *b, int c, int d, int e, int f, int g, int h);
extern "C" void _Z17SetElementFieldC2P15Struct_0205d81cii(void *self, int a, int b);

// USA: func_ov012_0218a054  (semantic: BuildAndEnqueueMessages_0218a054)
extern "C" ARM void func_ov012_0218a054(char *self) {
    func_ov012_021893b4(self, 0x10, 0x17, 0x15);
    memset(*(void **)(self + 0x1374), 0, 0x960);
    func_0205d304(self + 0xac, *(void **)(self + 0x1374), 0, 0, 0, 1, 0, 0);

    func_ov012_021893b4(self, 8, 0xa, 8);
    memset(*(void **)(self + 0x1374), 0, 0x960);
    func_ov012_0218a2b8(self, *(void **)(self + 0x1374), 0);
    func_0205d304(self + 0xac, *(void **)(self + 0x1374), 0, 1, 0, 1, 0, 0);

    func_ov012_021893b4(self, 7, 0x13, 8);
    memset(*(void **)(self + 0x1374), 0, 0x960);
    func_ov012_0218a1f4(self, *(void **)(self + 0x1374), 0);
    func_0205d304(self + 0xac, *(void **)(self + 0x1374), 0, 1, 0, 1, 0, 0);

    func_ov012_021893b4(self, *(unsigned char *)(self + 0x1371), 1, 8);
    memset(*(void **)(self + 0x1374), 0, 0x960);
    func_ov012_0218a374(self, *(void **)(self + 0x1374), 0);
    func_0205d304(self + 0xac, *(void **)(self + 0x1374), 0, 1, 0, 1, 0, 0);

    _Z17SetElementFieldC2P15Struct_0205d81cii(self + 0xac, 0x10, 0);
}
