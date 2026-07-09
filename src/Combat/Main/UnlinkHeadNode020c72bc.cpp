#include <globaldefs.h>

struct Node020c72bc {
    char pad[0x10];
    struct Node020c72bc* next;
    struct Node020c72bc* prev;
};

struct List020c72bc {
    struct Node020c72bc* head;
    struct Node020c72bc* tail;
};

// USA: func_020c72bc
ARM struct Node020c72bc* UnlinkHeadNode020c72bc(struct List020c72bc* list) {
    struct Node020c72bc* first = list->head;
    if (first != NULL) {
        struct Node020c72bc* next = first->next;
        list->head = next;
        if (next != NULL) {
            next->prev = NULL;
        } else {
            list->tail = NULL;
        }
    }
    return first;
}
