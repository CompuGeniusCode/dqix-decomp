#include <globaldefs.h>

struct Node021e244c {
    char pad0[8];
    struct Node021e244c* next;
};
struct List021e244c {
    struct Node021e244c* head;
};

// USA: func_ov025_021e244c
ARM void RemoveNode021e244c(struct List021e244c* list, struct Node021e244c* target) {
    struct Node021e244c* node = list->head;
    struct Node021e244c* prev = NULL;
    while (node != NULL) {
        if (node == target) {
            if (prev != NULL) {
                prev->next = node->next;
            } else {
                list->head = node->next;
            }
            target->next = NULL;
            return;
        }
        prev = node;
        node = node->next;
    }
}
