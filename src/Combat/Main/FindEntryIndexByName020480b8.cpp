#include <globaldefs.h>
#include "std_library_functions.h"

struct Table020480b8 {
    int count;
    char* entries;
};

// USA: func_020480b8
ARM int FindEntryIndexByName020480b8(struct Table020480b8* table, char* key) {
    int i;
    for (i = 0; i < table->count; i++) {
        if (strcmp(key, table->entries + i * 30) == 0) return i;
    }
    return 0;
}
