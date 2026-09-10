#include <globaldefs.h>

struct ListNodeHeader;
extern "C" void ResetListNodeHeader(struct ListNodeHeader* p);

struct ListNode {
    char unknown0[2];
    unsigned char inList;
    char unknown3;
    struct ListNode* next;
};

struct NodeList {
    struct ListNode* head;
    struct ListNode* tail;
};

// The tail is rebuilt by walking from the head, so removing a node is O(n) in the list length. It
// is the list the curated IsListEmpty works on, and the one AppendNodeToTail (0x020469b4, still a
// labeling-pass name, not curated) appends to; gamemain keeps its queues in it, at work+0x3704,
// where func_020e3b8c pairs the two, and at work+0x3000+0x6fc. A node that is not
// in the list is left alone, and so is its header. unknown0 covers the two bytes ResetListNodeHeader
// blanks alongside inList, the first of them the signed char id GetListHeadId returns and the reset
// sets to -1. AppendNodeToTail and func_020469f8 both set inList; unknown3 is cleared by
// func_020469f8 on the head it displaces and, as AppendNodeToTail's comment records, set by the
// undecompiled func_02046968 on the node that stops a pop, which is all that is established about
// that byte.
extern "C" ARM void RemoveNodeFromList(struct NodeList* list, struct ListNode* nodeToRemove) {
    struct ListNode* cur = list->head;
    if (cur == 0) return;
    if (cur == nodeToRemove) {
        list->head = nodeToRemove->next;
    } else {
        struct ListNode* next = cur->next;
        if (next == 0) return;
        while (next != nodeToRemove) {
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
    ResetListNodeHeader((struct ListNodeHeader*)nodeToRemove);
}
