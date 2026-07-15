#include <globaldefs.h>

struct Node02162d88 { char pad[2]; short key; };

// USA: func_ov000_02162d88
ARM void* FindNodeByShortKey02162d88(void* obj, short key) {
    int i;
    for (i = 0; i < 4; i++) {
        struct Node02162d88* node = *(struct Node02162d88**)((char*)obj + i * 4 + 0xeb8);
        if (node == 0) continue;
        if (key == node->key) return node;
    }
    return 0;
}
