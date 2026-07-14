#include <globaldefs.h>
#include "std_library_functions.h"

struct Entry02040404 {
    char name[0x38];
    int flag;
};

struct Container02040404 {
    unsigned int count;
    int unk4;
    struct Entry02040404* entries;
};

// USA: func_02040404
ARM int FindEntryIndexByName02040404(struct Container02040404* container, const char* name) {
    unsigned int i;
    struct Entry02040404* entries = container->entries;
    if (entries == NULL) {
        return -1;
    }
    for (i = 0; i < container->count; i++) {
        if (entries[i].flag < 0) {
            continue;
        }
        if (strcmp((char*)&entries[i], name) == 0) {
            return i;
        }
    }
    return -1;
}
