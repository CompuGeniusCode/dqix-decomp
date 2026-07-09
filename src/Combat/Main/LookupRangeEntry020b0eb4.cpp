#include <globaldefs.h>
#pragma optimize_for_size off

struct Node020b0eb4 {
    unsigned short lo;
    unsigned short hi;
    struct Node020b0eb4* next;
    unsigned char data[4];
};

struct Holder020b0eb4 {
    unsigned char pad0[0xc];
    struct Node020b0eb4* head;
};

// USA: func_020b0eb4
ARM void* LookupRangeEntry020b0eb4(struct Holder020b0eb4** slot, unsigned int key) {
    struct Node020b0eb4* node = (*slot)->head;
    if (node != NULL) {
        do {
            if (node->lo <= key && key <= node->hi) {
                return (char*)node + 8 + (key - node->lo) * 3;
            }
            node = node->next;
        } while (node != NULL);
    }
    return (char*)*slot + 4;
}
