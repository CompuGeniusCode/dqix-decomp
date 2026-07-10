#include <globaldefs.h>

extern "C" void func_020c64a0(int, int, int);
extern "C" void func_020c64fc(int, int, int);
extern "C" void func_020c663c(void);

// USA: func_020bb998
ARM void ForwardArgsToPairThenFinalize020bb998(int a, int b, int c) {
    func_020c64a0(a, b, c);
    func_020c64fc(a, b, c);
    func_020c663c();
}
