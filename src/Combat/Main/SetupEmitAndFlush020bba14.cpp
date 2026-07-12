#include <globaldefs.h>
void SendOrCopyBlockToRegion020c6864(int, int);

extern "C" void func_020c676c(int a, int b, int c);
extern "C" void func_020c68d0(void);

// USA: func_020bba14
ARM void SetupEmitAndFlush020bba14(int a, int b, int c) {
    func_020c676c(a, b, c);
    SendOrCopyBlockToRegion020c6864((int)(a), (int)(c));
    func_020c68d0();
}
