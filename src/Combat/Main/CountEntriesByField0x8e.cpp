#include <globaldefs.h>

struct Elem02026abc {
    unsigned short value;
    unsigned char gap[2];
    unsigned short type;
    unsigned char pad[22];
};

struct List02026abc {
    unsigned char pad0[0x780];
    unsigned char count;
    unsigned char pad1[9];
    struct Elem02026abc elems[1];
};

// USA: func_02026abc
ARM int CountEntriesByField0x8e(struct List02026abc* list) {
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
