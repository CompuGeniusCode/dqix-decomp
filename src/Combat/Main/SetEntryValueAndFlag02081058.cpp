#include <globaldefs.h>

struct Entry02081058 {
    char unk0[0x2a];
    unsigned char flags2a;
    unsigned char value2b;
    unsigned char field2c;
    char unk2d[0x30 - 0x2d];
};

struct List0207f6ac;

extern struct Entry02081058* FindEntryByShortId0207f6ac(struct List0207f6ac*, int);

// USA: func_02081058
ARM void SetEntryValueAndFlag02081058(void* obj, int id, int value) {
    struct Entry02081058* e = FindEntryByShortId0207f6ac((struct List0207f6ac*)((char*)obj + 4), id);
    if (e == NULL) {
        return;
    }
    e->value2b = (unsigned char)value;
    e->field2c = 8;
    e->flags2a |= 0x20;
}
