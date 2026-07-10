#include <globaldefs.h>

struct Entry0207f0ac;
struct List0207f0ac;
struct Entry0207f0ac* FindEntryByShortId0207f0ac(struct List0207f0ac*, int);

// USA: func_020807fc
ARM void SetEntryScaledXY020807fc(void* obj, int id, int x, int y) {
    struct Entry0207f0ac* e = FindEntryByShortId0207f0ac((struct List0207f0ac*)((char*)obj + 0xc), id);
    if (e != NULL) {
        *(short*)((char*)e + 0xa) = x >> 3;
        *(short*)((char*)e + 0xc) = y >> 3;
    }
}
