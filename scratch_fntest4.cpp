#include <globaldefs.h>

extern "C" int SomeFunc(int x);
extern "C" void OtherWork(int x);

typedef int (*FnPtr)(int);
static FnPtr const s_fn = SomeFunc;

ARM int TestFn(int a, int b) {
    if (a != 0 && s_fn != 0) {
        OtherWork(b);
        int r = s_fn(b);
        return r;
    }
    return 0;
}
