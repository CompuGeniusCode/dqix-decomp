#include <globaldefs.h>

extern "C" int SomeFunc(int x);
extern "C" void OtherWork(int x);

ARM int TestFn(int a, int b) {
    int ok = (a != 0) & (SomeFunc != 0);
    if (ok) {
        OtherWork(b);
        return 1;
    }
    return 0;
}
