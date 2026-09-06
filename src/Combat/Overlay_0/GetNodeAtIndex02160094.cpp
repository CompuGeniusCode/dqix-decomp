#include <globaldefs.h>

struct ListNode02160094 {
    char pad[0x30];
    struct ListNode02160094* next;
};

struct List02160094 {
    char pad0[8];
    unsigned char count;
    char pad1[7];
    struct ListNode02160094* head;
};

// USA: func_ov000_02160094
ARM struct ListNode02160094* GetNodeAtIndex02160094(struct List02160094* list, int index) {
    struct ListNode02160094* node;
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
