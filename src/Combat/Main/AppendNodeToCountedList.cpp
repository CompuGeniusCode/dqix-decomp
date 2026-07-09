#include <globaldefs.h>

struct NodeBFAC {
    char _pad[0x14];
    struct NodeBFAC* next;
};

struct ContBFAC {
    char _pad[4];
    struct NodeBFAC* head;
    unsigned short count;
};

// USA: func_0207bfac
ARM void AppendNodeToCountedList(struct ContBFAC* c, struct NodeBFAC* node) {
    struct NodeBFAC** slot = &c->head;
    while (*slot != 0) {
        slot = &(*slot)->next;
    }
    *slot = node;
    c->count++;
}
