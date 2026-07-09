#include <globaldefs.h>

struct ListNode0x2037804 {
    struct ListNode0x2037804* head;
    char pad[0x24];
    struct ListNode0x2037804* next;
};

// USA: func_02037804
ARM void AppendToList0x2037804(struct ListNode0x2037804* list, struct ListNode0x2037804* node) {
    struct ListNode0x2037804* cur = list->head;
    if (cur == 0) {
        list->head = node;
        node->next = 0;
        return;
    }
    while (cur->next != 0) {
        cur = cur->next;
    }
    cur->next = node;
    node->next = 0;
}
