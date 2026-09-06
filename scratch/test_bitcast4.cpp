#include <globaldefs.h>

struct Node021d6148 { unsigned int type; Node021d6148* link; };
extern "C" void _Z23SetLinkIfType3_021d6148P12Node021d6148j(Node021d6148*, unsigned int);
extern "C" unsigned int _fflt(int);
extern "C" unsigned int _fdiv(unsigned int, unsigned int);

ARM int TestBitcast(int* local, Node021d6148* self) {
    unsigned int v = _fdiv(_fflt(local[0]), 0x45800000u);
    _Z23SetLinkIfType3_021d6148P12Node021d6148j(self, v);
    return 1;
}
