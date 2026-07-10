#include <globaldefs.h>

struct QNode0205e1e4 {
    char pad[0x18];
    struct QNode0205e1e4* next;  /* 0x18 */
};
struct QList0205e1e4 {
    struct QNode0205e1e4* head;  /* 0x0 */
    struct QNode0205e1e4* tail;  /* 0x4 */
    int count;                   /* 0x8 */
};

void PushInterruptDisableState(void);
extern "C" void func_020d8694(void);

// USA: func_0205e1e4
ARM struct QNode0205e1e4* DequeueNode(struct QList0205e1e4* list) {
    struct QNode0205e1e4* head;
    PushInterruptDisableState();
    head = list->head;
    if (head != NULL) {
        list->head = head->next;
        list->count--;
    }
    func_020d8694();
    return head;
}
