#include <globaldefs.h>

struct Node0208e778 {
    char _pad[0x6c];
    struct Node0208e778* next;
};

struct Cont0208e778 {
    char _pad[4];
    struct Node0208e778* head;
    unsigned short count;
};

// USA: func_0208e778
ARM void AppendNodeToCountedList0208e778(struct Cont0208e778* c, struct Node0208e778* node) {
    struct Node0208e778** slot = &c->head;
    while (*slot != 0) {
        slot = &(*slot)->next;
    }
    *slot = node;
    c->count++;
}
