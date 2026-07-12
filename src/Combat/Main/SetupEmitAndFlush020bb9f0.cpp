#include <globaldefs.h>
void SendOrCopyBlock020c67fc(int, int);

extern "C" void func_020c676c(int a, int b, int c);
extern "C" void func_020c68d0(void);

// USA: func_020bb9f0
ARM void SetupEmitAndFlush020bb9f0(int a, int b, int c) {
    func_020c676c(a, b, c);
    SendOrCopyBlock020c67fc((int)(a), (int)(c));
    func_020c68d0();
}
