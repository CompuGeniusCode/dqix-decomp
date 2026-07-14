#include <globaldefs.h>

struct List0207f0ac;
struct Entry0207f0ac;
Entry0207f0ac* FindEntryByShortId0207f0ac(List0207f0ac* list, int id);

struct List0207f6ac;
struct Entry0207f6ac;
Entry0207f6ac* FindEntryByShortId0207f6ac(List0207f6ac* list, int id);

// USA: func_020809c4
ARM void GetLookAndTurnOffsets020809c4(void* obj, int id, int id2, short* out1, short* out2) {
    Entry0207f0ac* e = FindEntryByShortId0207f0ac((List0207f0ac*)((char*)obj + 0xc), id);
    if (e == NULL) {
        return;
    }
    *out1 = (short)(*(short*)((char*)e + 0xa) << 3);
    *out2 = (short)(*(short*)((char*)e + 0xc) << 3);
    for (unsigned char i = 0; i < *(unsigned char*)((char*)e + 0x13); i++) {
        short* arr = *(short**)((char*)e);
        if (id2 == arr[i]) {
            Entry0207f6ac* e2 = FindEntryByShortId0207f6ac((List0207f6ac*)((char*)obj + 4), id2);
            if (e2 == NULL) {
                return;
            }
            *out1 = *out1 + *(short*)((char*)e2 + 0x6);
            *out2 = *out2 + *(short*)((char*)e2 + 0x8);
            return;
        }
    }
}
