#include <globaldefs.h>
#include "std_library_functions.h"

struct Entry02034768 { char name[0x24]; };
struct Table02034768 {
    Entry02034768* entries;
    unsigned short count;
};

// USA: func_02034768
ARM int FindEntryByName02034768(Table02034768* table, const char* name) {
    int i;
    for (i = 0; i < table->count; i++) {
        if (strcmp((const char*)&table->entries[i], name) == 0)
            return i;
    }
    return -1;
}
