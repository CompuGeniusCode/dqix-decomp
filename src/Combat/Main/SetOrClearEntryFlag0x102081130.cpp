#include <globaldefs.h>

struct Entry02081130 {
    char unk0[0x15];
    unsigned char flags15;
    char unk16[0x18 - 0x16];
};

struct List0207f0ac;

extern struct Entry02081130* FindEntryByShortId0207f0ac(struct List0207f0ac*, int);

// USA: func_02081130
ARM void SetOrClearEntryFlag0x102081130(void* obj, int id, int flag) {
    struct Entry02081130* e = FindEntryByShortId0207f0ac((struct List0207f0ac*)((char*)obj + 0xc), id);
    if (e == NULL) {
        return;
    }
    if (flag != 0) {
        e->flags15 |= 1;
    } else {
        e->flags15 &= ~1;
    }
}
