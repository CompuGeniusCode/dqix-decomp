#include <globaldefs.h>

struct Node_375cc {
    char pad[0x28];
    struct Node_375cc* next;
};

struct Holder_375cc {
    char pad[0xc];
    struct Node_375cc* head;
};

// USA: func_020375cc
ARM struct Node_375cc* GetListNodeAtIndex(struct Holder_375cc* holder, int index) {
    struct Node_375cc* node;
    node = holder->head;
    while (node != 0) {
        if (index == 0) {
            return node;
        }
        node = node->next;
        index--;
    }
    return node;
}
