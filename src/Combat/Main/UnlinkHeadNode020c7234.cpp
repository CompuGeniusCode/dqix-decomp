#include <globaldefs.h>

struct Node020c7234 {
    char pad[0x78];
    void* f78;
    struct Node020c7234* prev;
    struct Node020c7234* next;
};

struct List020c7234 {
    struct Node020c7234* head;
    struct Node020c7234* tail;
};

// USA: func_020c7234
ARM struct Node020c7234* UnlinkHeadNode020c7234(struct List020c7234* list) {
    struct Node020c7234* first = list->head;
    if (first != NULL) {
        struct Node020c7234* next = first->next;
        list->head = next;
        if (next != NULL) {
            next->prev = NULL;
        } else {
            list->tail = NULL;
            first->f78 = NULL;
        }
    }
    return first;
}
