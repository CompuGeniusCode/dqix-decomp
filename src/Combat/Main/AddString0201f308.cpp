#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct StrTable0201f308 {
    char pad[0x18];
    char* slots[8];
    unsigned char count;
};

// USA: func_0201f308
ARM void AddString0201f308(struct StrTable0201f308* table, char* src, SafeAllocator* alloc) {
    table->slots[table->count] = (char*)alloc->Allocate(strlen(src) + 1);
    if (table->slots[table->count] != NULL) {
        strcpy(table->slots[table->count], src);
        table->count++;
    }
}
