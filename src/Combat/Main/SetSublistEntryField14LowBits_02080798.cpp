#include <globaldefs.h>

struct List0207f6ac;

struct Entry02080798 {
    char pad[0x14];
    unsigned char field14;
};

extern struct Entry02080798* FindEntryByShortId0207f6ac(struct List0207f6ac* list, int id);

// USA: func_02080798
ARM void SetSublistEntryField14LowBits_02080798(void* obj, int id, int value) {
    struct Entry02080798* e = FindEntryByShortId0207f6ac((struct List0207f6ac*)((char*)obj + 4), id);
    if (e != NULL) {
        e->field14 = (e->field14 & ~3) | (value & 3);
    }
}
