#include <globaldefs.h>

struct Entry02089fb0 {
    signed char id;
    unsigned char pad[0x3f];
};

struct EntryArray02089fb0 {
    struct Entry02089fb0* base;
    short count;
};

// USA: func_02089fb0
ARM struct Entry02089fb0* FindEntryBySignedId02089fb0(struct EntryArray02089fb0* arr, int id) {
    short i;
    if (id < 0) {
        return 0;
    }
    if (arr->base == 0) {
        return 0;
    }
    if (arr->count == 0) {
        return 0;
    }
    for (i = 0; i < arr->count; i++) {
        signed char entryId = arr->base[i].id;
        if (entryId == id) {
            return &arr->base[i];
        }
    }
    return 0;
}
