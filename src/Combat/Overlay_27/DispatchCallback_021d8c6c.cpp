#include <globaldefs.h>

typedef void (*Callback021d8c6c)(int, int, int);

struct RootStruct021d8c6c { void* field0; };
extern RootStruct021d8c6c data_ov027_021e33ec;

// USA: func_ov027_021d8c6c  (semantic: DispatchCallback_021d8c6c)
extern "C" ARM void func_ov027_021d8c6c(int a, int b, int c) {
    Callback021d8c6c cb = *(Callback021d8c6c*)((char*)data_ov027_021e33ec.field0 + 0x14e4);
    if (cb) cb(a, b, c);
}
