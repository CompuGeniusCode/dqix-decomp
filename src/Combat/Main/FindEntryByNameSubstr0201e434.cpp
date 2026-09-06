#include <globaldefs.h>
#include "std_library_functions.h"

struct Entry0201e434 {
    char pad[0xb];
    char name[5];
};

struct List0201e434 {
    char pad[0x30];
    Entry0201e434* entries;
    int count;
};

// USA: func_0201e434
ARM Entry0201e434* FindEntryByNameSubstr0201e434(List0201e434* list, const char* substr) {
    Entry0201e434* e = list->entries;
    for (int i = 0; i < list->count; i++, e++) {
        if (strstr(e->name, substr) != NULL)
            return e;
    }
    return NULL;
}
