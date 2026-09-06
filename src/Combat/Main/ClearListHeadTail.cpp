#include <globaldefs.h>

struct List02046958 {
    void* head;
    void* tail;
};

// USA: func_02046958
ARM void ClearListHeadTail(struct List02046958* list) {
    list->head = NULL;
    list->tail = NULL;
}
