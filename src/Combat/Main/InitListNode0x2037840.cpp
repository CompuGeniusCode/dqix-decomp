#include <globaldefs.h>

struct ListNode0x2037840 {
    char pad[0x92];
    short id;
    int prev;
    int next;
};

// USA: func_02037840
ARM void InitListNode0x2037840(struct ListNode0x2037840* node) {
    node->prev = 0;
    node->next = 0;
    node->id = -1;
}
