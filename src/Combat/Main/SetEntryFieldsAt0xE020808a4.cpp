#include <globaldefs.h>

struct Entry0207f0ac;
struct List0207f0ac;
struct Entry0207f0ac* FindEntryByShortId0207f0ac(struct List0207f0ac*, int);

// USA: func_020808a4
ARM void SetEntryFieldsAt0xE020808a4(void* obj, int id, int x, int y) {
    struct Entry0207f0ac* e = FindEntryByShortId0207f0ac((struct List0207f0ac*)((char*)obj + 0xc), id);
    if (e != NULL) {
        *(short*)((char*)e + 0xe) = x;
        *(short*)((char*)e + 0x10) = y;
    }
}
