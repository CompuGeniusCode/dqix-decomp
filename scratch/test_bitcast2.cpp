#include <globaldefs.h>

struct Node021d6148 { unsigned int type; Node021d6148* link; };
extern "C" void _Z23SetLinkIfType3_021d6148P12Node021d6148j(Node021d6148*, unsigned int);

union F2U { float f; unsigned int u; };

ARM int TestBitcast(int* local, Node021d6148* self) {
    F2U conv;
    conv.f = (float)local[0] / 4096.0f;
    _Z23SetLinkIfType3_021d6148P12Node021d6148j(self, conv.u);
    return 1;
}
