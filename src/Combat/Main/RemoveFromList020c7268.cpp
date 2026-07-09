#include <globaldefs.h>

struct Node020c7268 {
    char pad[0x7c];
    struct Node020c7268* prev;
    struct Node020c7268* next;
};

struct List020c7268 {
    struct Node020c7268* head;
    struct Node020c7268* tail;
};

// USA: func_020c7268
ARM struct Node020c7268* RemoveFromList020c7268(struct List020c7268* list, struct Node020c7268* target) {
    struct Node020c7268* cur = list->head;
    if (cur != NULL) {
        do {
            struct Node020c7268* next = cur->next;
            if (cur == target) {
                struct Node020c7268* prev = cur->prev;
                if (list->head == cur) {
                    list->head = next;
                } else {
                    prev->next = next;
                }
                if (list->tail == cur) {
                    list->tail = prev;
                } else {
                    next->prev = prev;
                }
                break;
            }
            cur = next;
        } while (cur != NULL);
    }
    return cur;
}
