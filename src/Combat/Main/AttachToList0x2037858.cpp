#include <globaldefs.h>

struct ListNode0x2037858 {
    char pad[0x92];
    short id;
    int prev;
    struct ListNode0x2037858* next;
};

// USA: func_02037858
ARM void AttachToList0x2037858(struct ListNode0x2037858* node, struct ListNode0x2037858* list, short id) {
    struct ListNode0x2037858* cur;
    if (node->prev != 0) {
        return;
    }
    node->id = id;
    cur = list;
    while (cur->next != 0) {
        cur = cur->next;
    }
    cur->next = node;
    node->prev = (int)cur;
    node->next = 0;
}
