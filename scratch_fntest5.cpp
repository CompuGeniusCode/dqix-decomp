#include <globaldefs.h>

extern "C" int SomeFunc(int x);
extern "C" void OtherWork(int x);

ARM int TestFn(int a, int b) {
    if (a != 0 && (int)SomeFunc != 0) {
        OtherWork(b);
        int r = SomeFunc(b);
        return r;
    }
    return 0;
}
