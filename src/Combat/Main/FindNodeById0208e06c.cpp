#include <globaldefs.h>

struct Node0208e06c {
    short id;
    short field2;
    int field4;
    struct Node0208e06c* next;
};

struct List0208e06c {
    struct Node0208e06c* head;
};

// USA: func_0208e06c
ARM struct Node0208e06c* FindNodeById0208e06c(struct List0208e06c* list, int id) {
    struct Node0208e06c* n;
    if (id < 0) {
        return NULL;
    }
    n = list->head;
    if (n == NULL) {
        return NULL;
    }
    while (n != NULL) {
        if (n->id == id) {
            return n;
        }
        n = n->next;
    }
    return n;
}
