#include <globaldefs.h>

struct Node02064530 {
    char pad0[0x14];
    struct Node02064530* next;  // 0x14
};

extern "C" int func_02061c04(void*, struct Node02064530*, void*);

// USA: func_02064530
ARM int ForEachNodeAllMatch02064530(void* a, struct Node02064530* node, void* c) {
    while (node != NULL) {
        if (func_02061c04(a, node, c) == 0) return 0;
        node = node->next;
    }
    return 1;
}
