#include <globaldefs.h>

struct QNode0205e18c {
    char pad[0x18];
    struct QNode0205e18c* next;  /* 0x18 */
};
struct QList0205e18c {
    struct QNode0205e18c* head;  /* 0x0 */
    struct QNode0205e18c* tail;  /* 0x4 */
    int count;                   /* 0x8 */
};

extern "C" void func_020d8654(void);
extern "C" void func_020d8694(void);

// USA: func_0205e18c
ARM void EnqueueNode(struct QList0205e18c* list, struct QNode0205e18c* node) {
    func_020d8654();
    if (list->head != NULL) {
        list->tail->next = node;
        list->tail = node;
    } else {
        list->head = node;
        list->tail = node;
        list->head->next = NULL;
    }
    list->count++;
    list->tail->next = NULL;
    func_020d8694();
}
