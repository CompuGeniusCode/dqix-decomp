#include <globaldefs.h>

struct Rec020467f0 {
    char tag;
    char pad1[0x3f];
    int size40;
    int field44;
    int size48;
};

// Returns the index'th entry's payload in a .pac archive directory, writing the entry header to
// *out and the payload length to *out44. The header is a 0x40-byte name, the payload offset at
// +0x40, the payload length at +0x44 and the stride to the next entry at +0x48, ending on a zeroed
// header; data/ani/bg_qm.pac parses byte-exactly that way. func_0208bf78, func_020941f8 and
// func_020a629c each hand a "*.pac" path to this and to CountPacEntries at 0x02046900, which walks
// the same chain. func_0204684c pairs with this one and matches on the extension instead.
extern "C" ARM void* GetPacEntryByIndex(struct Rec020467f0* rec, int index, void** out, int* out44) {
    int i;
    if (rec == NULL) return NULL;
    i = 0;
    while (rec->tag != 0) {
        if (index == i) {
            int size = rec->size40;
            if (out44 != NULL) *out44 = rec->field44;
            *out = rec;
            return (char*)rec + size;
        }
        rec = (struct Rec020467f0*)((char*)rec + rec->size48);
        i++;
    }
    return NULL;
}
