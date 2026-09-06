#include <globaldefs.h>
struct S { char pad[0x3c]; unsigned char f; };
extern "C" void Foo(void*, int, int, int, int);
extern "C" void Bar(S*, int);
ARM void Test(unsigned char* self, int a, int b, int c, int d, int e) {
    Foo(self, a, b, c, d);
    Bar((S*)(self+0x138), e);
    ((S*)(self+0x138))->f = 0;
}
