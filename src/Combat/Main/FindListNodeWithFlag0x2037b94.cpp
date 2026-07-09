#include <globaldefs.h>

struct ListNode0x2037b94 {
    unsigned short id;
    char pad[0x32];
    struct ListNode0x2037b94* next;
};

struct ListHead0x2037b94 {
    char pad[0xa8];
    struct ListNode0x2037b94* head;
};

// USA: func_02037b94
ARM struct ListNode0x2037b94* FindListNodeWithFlag0x2037b94(struct ListHead0x2037b94* owner, unsigned short id) {
    struct ListNode0x2037b94* node = owner->head;
    while (node != 0) {
        if (node->id == id) {
            return node;
        }
        node = node->next;
    }
    return 0;
}
