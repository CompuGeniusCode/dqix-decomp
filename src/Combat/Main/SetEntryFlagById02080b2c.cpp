#include <globaldefs.h>

struct List0207f6ac;
int SetEntryFlagBits0207f7ac(struct List0207f6ac*, int, int);

// USA: func_02080b2c
ARM int SetEntryFlagById02080b2c(void* obj, int id) {
    return SetEntryFlagBits0207f7ac((struct List0207f6ac*)((char*)obj + 4), id, 1);
}
