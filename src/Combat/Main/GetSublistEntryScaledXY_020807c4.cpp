#include <globaldefs.h>

struct List0207f0ac;

struct Entry020807c4 {
    char pad[0xa];
    short field_a;
    short field_c;
};

extern struct Entry020807c4* FindEntryByShortId0207f0ac(struct List0207f0ac* list, int id);

// USA: func_020807c4
ARM void GetSublistEntryScaledXY_020807c4(void* obj, int id, short* outX, short* outY) {
    struct Entry020807c4* e = FindEntryByShortId0207f0ac((struct List0207f0ac*)((char*)obj + 0xc), id);
    if (e != NULL) {
        *outX = e->field_a << 3;
        *outY = e->field_c << 3;
    }
}
