#include <globaldefs.h>

struct Node {
    char unk[0x10];
    struct Node* next;
    struct Node* prev;
};

struct List {
    char unk[0x88];
    struct Node* head;
    struct Node* tail;
};

// USA: func_020c8204
ARM void AppendToList(struct List* list, struct Node* node) {
    struct Node* tail = list->tail;
    if (tail == 0) {
        list->head = node;
    } else {
        tail->next = node;
    }
    node->prev = tail;
    node->next = 0;
    list->tail = node;
}
