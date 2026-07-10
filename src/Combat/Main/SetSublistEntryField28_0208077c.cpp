#include <globaldefs.h>

struct List0207f6ac;

struct Entry0208077c {
    char pad[0x28];
    short field28;
};

extern struct Entry0208077c* FindEntryByShortId0207f6ac(struct List0207f6ac* list, int id);

// USA: func_0208077c
ARM void SetSublistEntryField28_0208077c(void* obj, int id, short value) {
    struct Entry0208077c* e = FindEntryByShortId0207f6ac((struct List0207f6ac*)((char*)obj + 4), id);
    if (e != NULL) {
        e->field28 = value;
    }
}
