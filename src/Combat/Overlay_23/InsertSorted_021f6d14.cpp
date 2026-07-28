#include <globaldefs.h>

struct ListNode021f6d14 {
    unsigned int key;
    int pad4;
    struct ListNode021f6d14* prev;
    struct ListNode021f6d14* next;
};

struct List021f6d14 { char pad[0x28]; struct ListNode021f6d14* head; };

// USA: func_ov023_021f6d14  (semantic: InsertSorted_021f6d14)
extern "C" ARM void func_ov023_021f6d14(struct List021f6d14* list, struct ListNode021f6d14* node) {
    if (node == NULL) return;
    node->prev = NULL;
    node->next = NULL;
    struct ListNode021f6d14* cur = list->head;
    if (cur == NULL) {
        list->head = node;
        return;
    }
    while (cur != NULL) {
        if (node->key < cur->key) {
            if (cur->prev != NULL) {
                cur->prev->next = node;
            }
            node->next = cur;
            node->prev = cur->prev;
            cur->prev = node;
            if (cur == list->head) {
                list->head = node;
            }
            return;
        }
        if (cur->next == NULL) {
            cur->next = node;
            node->prev = cur;
            return;
        }
        cur = cur->next;
    }
}
