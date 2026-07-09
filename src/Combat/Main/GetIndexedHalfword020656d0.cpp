#include <globaldefs.h>

struct IndexedHalfword020656d0 {
    char pad0[0x4c];
    unsigned short* table;
    char pad1[0x78 - 0x50];
    int index;
};

// USA: func_020656d0
ARM unsigned short GetIndexedHalfword(struct IndexedHalfword020656d0* obj) {
    return obj->table[obj->index];
}
