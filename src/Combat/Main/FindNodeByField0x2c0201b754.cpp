#include <globaldefs.h>

extern "C" void* func_0201e838(void*, int);

struct Node0201b754 {
    unsigned char pad0[0x2c];
    unsigned short f2c;
    unsigned char pad2e[0x42];
    struct Node0201b754* f70;
};

// USA: func_0201b754
ARM struct Node0201b754* FindNodeByField0x2c0201b754(void* obj, int key) {
    struct Node0201b754* node = (struct Node0201b754*)func_0201e838((char*)obj + 0x6c, 0xa);
    while (node != 0) {
        if (node->f2c == key) return node;
        node = node->f70;
    }
    return 0;
}
