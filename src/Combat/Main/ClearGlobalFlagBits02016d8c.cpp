#include <globaldefs.h>

extern "C" void func_020ca528(void* a, void* b);
extern int data_0210a0cc;

struct FlagBlock02016d8c { int pad[0x3f]; int flags; };
extern FlagBlock02016d8c data_0210a010;

// USA: func_02016d8c
ARM void ClearGlobalFlagBits02016d8c(void* arg0) {
    func_020ca528(arg0, &data_0210a0cc);
    data_0210a010.flags &= ~0xa4;
}
