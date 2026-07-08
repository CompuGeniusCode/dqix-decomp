#include <globaldefs.h>

struct LinkNode {
    char unk[0x10];
    struct LinkNode* next;
    struct LinkNode* prev;
};

struct LinkAnchor {
    char unk[0x88];
    struct LinkNode* head;
    struct LinkNode* tail;
};

// USA: func_020c8228
ARM void UnlinkNode(struct LinkAnchor* anchor, struct LinkNode* node) {
    struct LinkNode* next = node->next;
    struct LinkNode* prev = node->prev;
    if (next == 0) {
        anchor->tail = prev;
    } else {
        next->prev = prev;
    }
    if (prev == 0) {
        anchor->head = next;
    } else {
        prev->next = next;
    }
}
