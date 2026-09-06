#include <globaldefs.h>

struct ListNode021600f8 {
    char pad[0x20];
    struct ListNode021600f8* next;
};

struct List021600f8 {
    char pad0[9];
    unsigned char count;
    char pad1[10];
    struct ListNode021600f8* head;
};

// USA: func_ov000_021600f8
ARM struct ListNode021600f8* GetNodeAtIndex021600f8(struct List021600f8* list, int index) {
    struct ListNode021600f8* node;
    int i;
    if (list->count <= index) return 0;
    node = list->head;
    i = 0;
    while (i < index && node != 0) {
        node = node->next;
        i++;
    }
    return node;
}
