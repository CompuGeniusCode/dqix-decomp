#include <globaldefs.h>
struct S { char pad[0x3c]; unsigned char f; };
extern "C" void Foo(S*, int);
ARM void Test(unsigned char* self, int e) {
    Foo((S*)(self+0x138), e);
    ((S*)(self+0x138))->f = 0;
}
