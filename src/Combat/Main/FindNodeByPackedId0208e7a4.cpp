#include <globaldefs.h>

struct Node0208e7a4 {
    unsigned int packed;              // 0x0
    char pad[0x6c - 4];               // 0x4..0x6b
    struct Node0208e7a4* next;        // 0x6c
};

struct Head0208e7a4 {
    char pad[4];                      // 0x0..0x3
    struct Node0208e7a4* head;        // 0x4
};

// USA: func_0208e7a4
ARM struct Node0208e7a4* FindNodeByPackedId0208e7a4(struct Head0208e7a4* owner, unsigned int key) {
    struct Node0208e7a4* node = owner->head;
    while (node != NULL) {
        if (key == ((node->packed << 9) >> 25)) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}
