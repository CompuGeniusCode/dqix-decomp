#include <globaldefs.h>

struct Entry0207f6ac;
struct List0207f6ac;
struct Entry0207f6ac* FindEntryByShortId0207f6ac(struct List0207f6ac*, int);

// USA: func_02080828
ARM void GetEntryFieldsAt0x602080828(void* obj, int id, short* outX, short* outY) {
    struct Entry0207f6ac* e = FindEntryByShortId0207f6ac((struct List0207f6ac*)((char*)obj + 0x4), id);
    if (e != NULL) {
        *outX = *(short*)((char*)e + 0x6);
        *outY = *(short*)((char*)e + 0x8);
    }
}
