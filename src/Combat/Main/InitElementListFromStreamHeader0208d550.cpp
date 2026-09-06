#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
extern "C" extern int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct ElementList0208d8ec;
extern void InitElementList0208d8ec(struct ElementList0208d8ec* obj, SafeAllocator* alloc, int capacity);

struct StreamHeader0208d860 {
    unsigned int w0;
    unsigned short h4;
    unsigned short h6;
    unsigned int w8;
    short hc;
    unsigned short he;
};

struct Data02108fc0Type {
    void* field0;
    struct StreamHeader0208d860* field4;
};
extern struct Data02108fc0Type data_02108fc0;

// USA: func_0208d550
extern "C" ARM int func_0208d550(struct Variant02030b0c* v) {
    short val = (short)_ZNK6Script9Parameter5ToIntEv(v);
    if (data_02108fc0.field4->hc != 0) {
        InitElementList0208d8ec((struct ElementList0208d8ec*)data_02108fc0.field4, (SafeAllocator*)data_02108fc0.field0, data_02108fc0.field4->hc);
    } else {
        InitElementList0208d8ec((struct ElementList0208d8ec*)data_02108fc0.field4, (SafeAllocator*)data_02108fc0.field0, val);
    }
    return 1;
}
