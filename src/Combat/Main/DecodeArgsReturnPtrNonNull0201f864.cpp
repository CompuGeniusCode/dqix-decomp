#include <globaldefs.h>

struct Variant02030b0c { int tag; union { int i; float f; } u; };
struct Struct02030b7c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(Variant02030b0c* p);
extern "C" void* _ZNK6Script9Parameter8ToStringEv(Struct02030b7c* s);

// USA: func_0201f864
ARM int DecodeArgsReturnPtrNonNull0201f864(Variant02030b0c* args) {
    void* p;
    _ZNK6Script9Parameter5ToIntEv(args);
    p = _ZNK6Script9Parameter8ToStringEv((Struct02030b7c*)(args + 1));
    _ZNK6Script9Parameter5ToIntEv(args + 2);
    return p != NULL ? 1 : 0;
}
