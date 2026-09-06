#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct S020556cc;
bool AllocateAndInitObject020556dc(void** out, SafeAllocator* alloc);
void StoreThreeFields020556cc(struct S020556cc* p, int a, int b, int c);
extern "C" void func_02056d80(void* obj);

struct Obj02055718 {
    int f0;
    void* f4;
    int f8;
    int fc;
};

// USA: func_02055718
ARM int InitAllocatedObject02055718(Obj02055718* p, int a, int b) {
    if (a == 0) return 0;
    if (b == 0) return 0;
    p->f0 = b;
    p->f8 = a;
    if (AllocateAndInitObject020556dc(&p->f4, (SafeAllocator*)p->f0)) {
        StoreThreeFields020556cc((struct S020556cc*)p->f4, p->fc, p->f8, p->f0);
        func_02056d80(p->f4);
    }
    return 1;
}
