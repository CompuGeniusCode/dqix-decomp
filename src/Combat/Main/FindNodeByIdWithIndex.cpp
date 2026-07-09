#include <globaldefs.h>

struct NodeBFD8 {
    unsigned short id;
    char _pad[0x12];
    struct NodeBFD8* next;
};

struct ContBFD8 {
    char _pad[4];
    struct NodeBFD8* head;
};

// USA: func_0207bfd8
ARM struct NodeBFD8* FindNodeByIdWithIndex(struct ContBFD8* c, unsigned short key, unsigned short* outIndex) {
    unsigned short idx = 0;
    struct NodeBFD8* node = c->head;
    while (node != 0) {
        if (node->id == key) {
            if (outIndex != 0) {
                *outIndex = idx;
            }
            return node;
        }
        idx++;
        node = node->next;
    }
    return 0;
}
