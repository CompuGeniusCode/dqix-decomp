#include <globaldefs.h>

extern "C" void func_020c6688(int, int, int);
extern "C" void func_020c66bc(int, int, int);
extern "C" void func_020c6728(void);

// USA: func_020bb9c4
ARM void ForwardArgsToPairThenFinalize020bb9c4(int a, int b, int c) {
    func_020c6688(a, b, c);
    func_020c66bc(a, b, c);
    func_020c6728();
}
