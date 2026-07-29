#include <globaldefs.h>

struct Node020b2d60 {
    char pad[0x10];
    struct Node020b2d60* next;
};

struct List020b2d60 {
    struct Node020b2d60* head;
};

// USA: func_020b2d60
ARM int RemoveNode020b2d60(struct List020b2d60* list, struct Node020b2d60* node) {
    struct Node020b2d60 *next, *head;
    head = list->head;
    if (head == 0) return 0;
    if (head == node) {
        list->head = *(struct Node020b2d60* volatile*)&head->next;
        node->next = 0;
        return 1;
    }
    next = head->next;
    if (next == 0) goto end;
    do {
        if (next == node) {
            head->next = next->next;
            next->next = 0;
            return 1;
        }
        head = next;
        next = next->next;
    } while (next != 0);
end:
    return 0;
}
