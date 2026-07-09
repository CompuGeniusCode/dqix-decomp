#include <globaldefs.h>

struct Node_1e6d4 {
    char unk0[4];
    int kind;
    char unk8[0x24];
    unsigned short id;
    char unk2e[0x42];
    struct Node_1e6d4* next;
};

struct NodeOwner_1e6d4 {
    char unk[0x60];
    struct Node_1e6d4* head;
};

// USA: func_0201e6d4
ARM struct Node_1e6d4* FindNodeKind9ById(struct NodeOwner_1e6d4* owner, int id) {
    struct Node_1e6d4* node;
    if (id < 0) {
        return 0;
    }
    node = owner->head;
    while (node != 0) {
        if (node->kind == 9 && node->id == id) {
            return node;
        }
        node = node->next;
    }
    return 0;
}
