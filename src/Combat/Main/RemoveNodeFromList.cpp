#include <globaldefs.h>

struct ByteHeader0204693c;
extern "C" void ResetListNodeHeader(struct ByteHeader0204693c* p);

struct Node02046a8c {
    char unk0[2];
    unsigned char inList;
    char unk3;
    struct Node02046a8c* next;
};

struct List02046a8c {
    struct Node02046a8c* head;
    struct Node02046a8c* tail;
};

// The tail is rebuilt by walking from the head, so removing a node is O(n) in the list length. It
// is the list the curated IsListEmpty works on, and the one AppendNodeToTail (0x020469b4, still a
// labeling-pass name, not curated) appends to; gamemain keeps its queues in it, at work+0x3704,
// where func_020e3b8c pairs the two, and at work+0x3000+0x6fc. A node that is not
// in the list is left alone, and so is its header.
extern "C" ARM void RemoveNodeFromList(struct List02046a8c* list, struct Node02046a8c* node) {
    struct Node02046a8c* cur = list->head;
    if (cur == 0) return;
    if (cur == node) {
        list->head = node->next;
    } else {
        struct Node02046a8c* next = cur->next;
        if (next == 0) return;
        while (next != node) {
            if (next == 0) return;
            cur = next;
            next = next->next;
        }
        cur->next = next->next;
    }
    cur = list->head;
    list->tail = 0;
    while (cur != 0) {
        list->tail = cur;
        cur = cur->next;
    }
    ResetListNodeHeader((struct ByteHeader0204693c*)node);
}
