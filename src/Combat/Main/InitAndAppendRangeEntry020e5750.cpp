#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Variant02030b0c;
struct Struct02030b7c;

struct RangeEntry020e587c {
    int field0;
    int field4;
    int lo;
    int hi;
    int field10;
};
struct RangeList020e587c;

int GetIntFromVariant02030b0c(struct Variant02030b0c* p);
void* GetField4IfField0Zero(struct Struct02030b7c* s);
int StringLength(const char* s);
void AppendRangeEntry020e587c(struct RangeList020e587c* list, struct RangeEntry020e587c* entry);

extern void* data_021536c4[2];

// USA: func_020e5750
ARM int InitAndAppendRangeEntry020e5750(void* param0) {
    struct RangeEntry020e587c entry;
    char* fmt;
    memset(&entry, 0, sizeof(entry));
    entry.lo = GetIntFromVariant02030b0c((struct Variant02030b0c*)param0);
    entry.hi = GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)param0 + 0x8));
    entry.field4 = GetIntFromVariant02030b0c((struct Variant02030b0c*)((char*)param0 + 0x10));
    fmt = (char*)GetField4IfField0Zero((struct Struct02030b7c*)((char*)param0 + 0x18));
    if (fmt) {
        int len = StringLength(fmt);
        char* buf = (char*)((SafeAllocator*)data_021536c4[0])->Allocate(len + 1);
        entry.field10 = (int)buf;
        sprintf(buf, fmt);
    }
    AppendRangeEntry020e587c((struct RangeList020e587c*)data_021536c4[1], &entry);
    return 1;
}
