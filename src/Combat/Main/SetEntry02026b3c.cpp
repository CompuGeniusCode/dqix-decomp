#include <globaldefs.h>
#include "std_library_functions.h"

struct Entry02026b3c {
    short id;
    char name[0x18];
};

struct Obj02026b3c {
    char pad[0x77a];
    unsigned char count;
    char pad2[1];
    Entry02026b3c* entries;
};

// USA: func_02026b3c
ARM void SetEntry02026b3c(Obj02026b3c* obj, unsigned int index, short id, const char* name) {
    if (index >= obj->count) return;
    if (obj->entries == NULL) return;
    obj->entries[index].id = id;
    strcpy(obj->entries[index].name, name);
}
