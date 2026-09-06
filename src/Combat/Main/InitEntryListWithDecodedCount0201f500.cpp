#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
struct Struct020277c4;
extern "C" int _ZNK6Script9Parameter5ToIntEv(Variant02030b0c* p);
void InitEntryList020277c4(Struct020277c4* obj, int count, SafeAllocator* alloc);
extern int data_020fdc4c;

// USA: func_0201f500
ARM int InitEntryListWithDecodedCount0201f500(Variant02030b0c* arg) {
    int count = _ZNK6Script9Parameter5ToIntEv(arg);
    InitEntryList020277c4(
        (Struct020277c4*)*(char**)((char*)&data_020fdc4c + 0x10),
        count,
        (SafeAllocator*)*(char**)((char*)&data_020fdc4c + 0x8));
    return 1;
}
