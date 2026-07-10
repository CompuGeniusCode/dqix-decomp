#include <globaldefs.h>

struct List0207f6ac;
int ClearEntryFlagBits0207f7cc(struct List0207f6ac*, int, int);

// USA: func_02080b40
ARM int SetEntryFlagById02080b40(void* obj, int id) {
    return ClearEntryFlagBits0207f7cc((struct List0207f6ac*)((char*)obj + 4), id, 1);
}
