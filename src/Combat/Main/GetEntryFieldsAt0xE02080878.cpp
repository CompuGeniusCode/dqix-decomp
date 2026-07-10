#include <globaldefs.h>

struct Entry0207f0ac;
struct List0207f0ac;
struct Entry0207f0ac* FindEntryByShortId0207f0ac(struct List0207f0ac*, int);

// USA: func_02080878
ARM void GetEntryFieldsAt0xE02080878(void* obj, int id, short* outX, short* outY) {
    struct Entry0207f0ac* e = FindEntryByShortId0207f0ac((struct List0207f0ac*)((char*)obj + 0xc), id);
    if (e != NULL) {
        *outX = *(short*)((char*)e + 0xe);
        *outY = *(short*)((char*)e + 0x10);
    }
}
