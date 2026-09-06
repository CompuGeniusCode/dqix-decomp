#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct StrTable0201f308;
struct Struct02030b7c;

void AddString0201f308(StrTable0201f308*, char*, SafeAllocator*);
extern "C" void* _ZNK6Script9Parameter8ToStringEv(Struct02030b7c*);

struct Container0201eff0 {
    int f0;
    SafeAllocator* alloc;      // +0x4
    StrTable0201f308* table;   // +0x8
};
extern Container0201eff0 data_020fdc40;

// USA: func_0201eff0
ARM int AddStringIfPresent0201eff0(Struct02030b7c* p) {
    char* str = (char*)_ZNK6Script9Parameter8ToStringEv(p);
    if (str != NULL) {
        AddString0201f308(data_020fdc40.table, str, data_020fdc40.alloc);
    }
    return 1;
}
