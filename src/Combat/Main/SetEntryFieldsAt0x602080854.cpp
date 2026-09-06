#include <globaldefs.h>

struct Entry0207f6ac;
struct List0207f6ac;
struct Entry0207f6ac* FindEntryByShortId0207f6ac(struct List0207f6ac*, int);

// USA: func_02080854
ARM void SetEntryFieldsAt0x602080854(void* obj, int id, int x, int y) {
    struct Entry0207f6ac* e = FindEntryByShortId0207f6ac((struct List0207f6ac*)((char*)obj + 0x4), id);
    if (e != NULL) {
        *(short*)((char*)e + 0x6) = x;
        *(short*)((char*)e + 0x8) = y;
    }
}
