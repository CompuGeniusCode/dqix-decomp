#include <globaldefs.h>

struct NodeDB20 {
    unsigned char id;
    char unk[0x67];
    struct NodeDB20* next;
};

// USA: func_0206db20
ARM struct NodeDB20* FindNodeByByteId(void* base, int key) {
    struct NodeDB20* node = *(struct NodeDB20**)base;
    while (node != 0) {
        if (node->id == key) {
            return node;
        }
        node = node->next;
    }
    return 0;
}
