#include <globaldefs.h>

struct Table021eea98 {
    char pad[0x950];
    int index;
};

struct Obj021eea98 {
    char pad[0x150];
    struct Table021eea98* table;
};

// USA: func_ov023_021eea98
ARM int GetTableEntry138_021eea98(struct Obj021eea98* o) {
    struct Table021eea98* t = o->table;
    return *(int*)((char*)t + (t->index * 4) + 0x138);
}
