#include <globaldefs.h>

struct ListNode0x2037a50 {
    char pad[0x94];
    int prev;
};

// USA: func_02037a50
ARM int IsListNodeAttached0x2037a50(struct ListNode0x2037a50* node) {
    return node->prev != 0;
}
