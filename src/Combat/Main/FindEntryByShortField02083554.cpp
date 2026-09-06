#include <globaldefs.h>
struct Entry02083554 { unsigned char pad[0x18]; short id; unsigned char pad2[6]; };
struct Container02083554 { unsigned char pad[0x194]; struct Entry02083554 entries[11]; };
// USA: func_02083554
ARM struct Entry02083554* FindEntryByShortField02083554(struct Container02083554* c, int id) {
    int i;
    for (i = 0; i < 0xb; i++) {
        if (id == c->entries[i].id) {
            return &c->entries[i];
        }
    }
    return 0;
}
