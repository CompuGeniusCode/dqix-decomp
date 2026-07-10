#include <globaldefs.h>
#include "std_library_functions.h"

struct Entry02040184 {
    char* name;
    char pad[0x10];
};
struct Table02040184 {
    void* base;
    char pad[0x14];
    unsigned int count;
    Entry02040184* entries;
};

// USA: func_02040184
ARM int FindEntryByName02040184(Table02040184* table, const char* name) {
    unsigned int i;
    if (table->base == NULL)
        return -1;
    for (i = 0; i < table->count; i++) {
        if (strcmp(name, table->entries[i].name) == 0)
            return i;
    }
    return -1;
}
