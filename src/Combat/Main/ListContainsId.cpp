#include <globaldefs.h>

struct ListNode02046b60 {
    signed char id;
    char pad[3];
    struct ListNode02046b60* next;
};

struct ListHead02046b60 {
    struct ListNode02046b60* head;
};

// USA: func_02046b60
ARM int ListContainsId(struct ListHead02046b60* list, int id) {
    struct ListNode02046b60* node = list->head;
    while (node != 0) {
        if (node->id == id) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}
