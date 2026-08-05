#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Struct02030b7c {
    int field0;
    void* field4;
};
void* GetField4IfField0Zero(struct Struct02030b7c* s);

int StringLength(const char* s);

struct Target020899fc {
    char pad0[0xc];
    char** array;   // 0xc
    short count;     // 0x10
};

struct Data02108efc {
    struct Target020899fc* target;  // 0x0
    char pad1[0xc - 4];
    SafeAllocator* allocator;         // 0xc
};
extern struct Data02108efc data_02108efc;

// USA: func_020899fc  (semantic: PopulateStringArrayFromElements020899fc)
extern "C" ARM int func_020899fc(struct Struct02030b7c* elements) {
    struct Target020899fc* target = data_02108efc.target;
    char** arr;
    short count = target->count;
    short i;
    arr = (char**)data_02108efc.allocator->Allocate(count * 4);

    for (i = 0; i < count; i++) {
        char* str = (char*)GetField4IfField0Zero(elements);
        elements++;

        int len = StringLength(str);
        char* buf = (char*)data_02108efc.allocator->Allocate(len + 1);
        arr[i] = buf;
        memset(arr[i], 0, len + 1);
        memcpy(arr[i], str, len);
    }

    data_02108efc.target->array = arr;
    return 1;
}
