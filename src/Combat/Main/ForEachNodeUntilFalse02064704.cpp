#include <globaldefs.h>

struct Node02064704 {
    char pad0[0xc];
    struct Node02064704* next;  // 0xc
};

extern "C" int func_0205faf4(void*, struct Node02064704*, void*);

// USA: func_02064704
ARM int ForEachNodeUntilFalse02064704(void* a, struct Node02064704* node, void* c) {
    while (node != NULL) {
        if (func_0205faf4(a, node, c) == 0) break;
        node = node->next;
    }
    return node == NULL;
}
