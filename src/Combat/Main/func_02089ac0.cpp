#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Struct02030b7c {
    int field0;
    void* field4;
};
extern "C" void* _ZNK6Script9Parameter8ToStringEv(struct Struct02030b7c* s);
int StringLength(const char* s);

struct Pool02089ac0 {
    char pad[0x14];
    char** strings;   // +0x14
    short count;      // +0x18
};

struct Ctx02108efc02089ac0 {
    struct Pool02089ac0* pool;
    int unk4;
    int unk8;
    SafeAllocator* alloc;
};
extern struct Ctx02108efc02089ac0 data_02108efc;

// USA: func_02089ac0
extern "C" ARM int func_02089ac0(struct Struct02030b7c* items) {
    char** strings;
    short count = data_02108efc.pool->count;
    strings = (char**)data_02108efc.alloc->Allocate(count * 4);
    for (short i = 0; i < count; i++) {
        char* text = (char*)_ZNK6Script9Parameter8ToStringEv(items);
        items = (struct Struct02030b7c*)((char*)items + 8);
        int len = StringLength(text);
        strings[i] = (char*)data_02108efc.alloc->Allocate(len + 1);
        memset(strings[i], 0, len + 1);
        memcpy(strings[i], text, len);
    }
    data_02108efc.pool->strings = strings;
    return 1;
}
