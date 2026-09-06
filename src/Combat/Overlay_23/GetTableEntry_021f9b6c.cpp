#include <globaldefs.h>

struct Obj9b6c {
    char pad[0x20];
    unsigned short* table;
    unsigned short count;
    unsigned short width;
};

// USA: func_ov023_021f9b6c
ARM unsigned int GetTableEntry_021f9b6c(struct Obj9b6c* obj, unsigned int a, unsigned int b) {
    if (!obj->table) return 0;
    if (obj->count <= a || obj->width <= b) return 0;
    return obj->table[a * obj->width + b];
}
