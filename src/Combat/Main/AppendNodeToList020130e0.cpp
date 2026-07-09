#include <globaldefs.h>

struct Node020130e0 {
    char unk[0x30];
    struct Node020130e0* next;
};

// USA: func_020130e0
ARM void AppendNodeToList020130e0(struct Node020130e0* list, struct Node020130e0* node) {
    struct Node020130e0* cur = list->next;
    if (cur == 0) {
        list->next = node;
        return;
    }
    while (cur->next != 0) {
        cur = cur->next;
    }
    cur->next = node;
}
