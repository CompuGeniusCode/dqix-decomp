#include <globaldefs.h>

struct ListNode0x2037840;
void InitListNode0x2037840(struct ListNode0x2037840* node);

struct ListNode020378dc {
    unsigned char pad[0x94];
    struct ListNode020378dc* prev;   // 0x94
    struct ListNode020378dc* next;    // 0x98
};

// USA: func_020378dc
ARM void UnlinkOrClearListNode020378dc(struct ListNode020378dc* node) {
    struct ListNode020378dc* prev = node->prev;
    struct ListNode020378dc* cur = node->next;
    if (prev != NULL) {
        prev->next = cur;
        if (node->next != NULL) {
            node->next->prev = node->prev;
        }
        InitListNode0x2037840((struct ListNode0x2037840*)node);
        return;
    }
    while (cur != NULL) {
        struct ListNode020378dc* n = cur->next;
        InitListNode0x2037840((struct ListNode0x2037840*)cur);
        cur = n;
    }
    InitListNode0x2037840((struct ListNode0x2037840*)node);
}
