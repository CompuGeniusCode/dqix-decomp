#include <globaldefs.h>

struct TailNode020469b4 {
    char unk0[2];
    unsigned char inList;
    char unk3;
    struct TailNode020469b4* next;
};

struct TailList020469b4 {
    struct TailNode020469b4* head;
    struct TailNode020469b4* tail;
};

// USA: func_020469b4
ARM void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node) {
    if (list->head != NULL && list->tail != NULL) {
        list->tail->next = node;
        list->tail = node;
        node->next = NULL;
    } else {
        list->head = node;
        list->tail = node;
        node->next = NULL;
    }
    node->next = NULL;
    node->inList = 1;
}
