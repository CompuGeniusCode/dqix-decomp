#include <globaldefs.h>

struct Elem02026a28 {
    unsigned short value;
    unsigned short type;
    unsigned char pad[24];
};

struct List02026a28 {
    unsigned char pad0[0x780];
    unsigned char count;
    unsigned char pad1[9];
    struct Elem02026a28 elems[1];
};

// USA: func_02026a28
ARM int CountEntriesByField0x8c(struct List02026a28* list) {
    unsigned char matches = 0;
    int i;
    for (i = 0; i < list->count; i++) {
        if (list->elems[i].type == 1) {
            if (list->elems[i].value != 5) {
                matches = matches + 1;
            }
        }
    }
    return matches;
}
