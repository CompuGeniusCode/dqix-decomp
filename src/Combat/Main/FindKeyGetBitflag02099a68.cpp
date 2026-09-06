#include <globaldefs.h>

struct SElem02099a68 {
    unsigned short key;
    unsigned char pad[12];
    unsigned char fe;
    unsigned char pad2;
};

struct SearchList02099a68 {
    struct SElem02099a68* data;
    int count;
};

// USA: func_02099a68
ARM int FindKeyGetBitflag02099a68(struct SearchList02099a68* list, unsigned short key) {
    int i;
    for (i = 0; i < list->count; i++) {
        if (key == list->data[i].key) {
            unsigned int v = list->data[i].fe;
            v = (v << 26) >> 28;
            if (v == 8) return 0;
            return 1 << v;
        }
    }
    return 0;
}
