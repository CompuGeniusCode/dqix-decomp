#include <globaldefs.h>

struct ListHead_021f67ac {
    void* first;
};

struct ListNode_021f67ac {
    char pad0[0x6];
    unsigned short flag;
    char pad1[0xc];
    struct ListNode_021f67ac* prev;
    struct ListNode_021f67ac* next;
};

// USA: func_ov023_021f67ac
ARM void AppendNodeToList_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node) {
    struct ListNode_021f67ac* cur;
    if (node->flag == 0) {
        return;
    }
    cur = (struct ListNode_021f67ac*)head->first;
    if (cur != NULL) {
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = node;
        node->prev = cur;
        return;
    }
    head->first = node;
}
