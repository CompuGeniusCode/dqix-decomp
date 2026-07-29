#include <globaldefs.h>

extern "C" int SomeFunc(int x);
extern "C" void OtherWork(int x);

ARM int TestFn(int a, int b) {
    if (a != 0 && SomeFunc != 0) {
        OtherWork(b);
        return 1;
    }
    return 0;
}
