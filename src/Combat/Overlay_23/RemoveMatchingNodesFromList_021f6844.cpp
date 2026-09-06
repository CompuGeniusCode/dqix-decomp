#include <globaldefs.h>

struct ListNode021f6844 {
    char pad0[0x8];
    unsigned short field8;
    char pad1[0x18 - 0x8 - 0x2];
    struct ListNode021f6844* next;
};

struct ListHead021f6844 {
    struct ListNode021f6844* first;
};

extern "C" void func_ov023_021f67ec(struct ListHead021f6844* head, struct ListNode021f6844* node);

// USA: func_ov023_021f6844  (semantic: RemoveMatchingNodesFromList_021f6844)
extern "C" ARM void func_ov023_021f6844(struct ListHead021f6844* head, unsigned short value) {
    struct ListNode021f6844* node = head->first;
    while (node != 0) {
        struct ListNode021f6844* next = node->next;
        if (node->field8 == value) {
            func_ov023_021f67ec(head, node);
        }
        node = next;
    }
}
