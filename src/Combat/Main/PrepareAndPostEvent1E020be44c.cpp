#include <globaldefs.h>

extern "C" void func_020be3f4(int a, int b, int c);
void PostEvent0x1E(int a, int b);

// USA: func_020be44c
ARM void PrepareAndPostEvent1E020be44c(int a0, int a1, int a2, int a3) {
    func_020be3f4(a0, a2, a3);
    PostEvent0x1E(a0, a0 + a1);
}
