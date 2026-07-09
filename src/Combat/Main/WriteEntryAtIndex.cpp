#include <globaldefs.h>

struct WriteEntry020e3b44 {
    unsigned int val;
    unsigned char tag;
    unsigned char b5;
    unsigned char b6;
    unsigned char pad;
};

// USA: func_020e3b44
ARM void WriteEntryAtIndex(struct WriteEntry020e3b44* entries, int index, struct WriteEntry020e3b44 entry) {
    if (index >= 0 && index < 4) {
        entries[index].val = entry.val;
        entries[index].tag = entry.tag;
        entries[index].b5 = entry.b5;
        entries[index].b6 = entry.b6;
    }
}
