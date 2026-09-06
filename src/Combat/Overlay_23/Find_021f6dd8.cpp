#include <globaldefs.h>

struct Node021f6dd8 { int f0; int f4; int pad8; Node021f6dd8* next; };

// USA: func_ov023_021f6dd8
ARM int Find_021f6dd8(void* obj, int amt) {
    Node021f6dd8* node = *(Node021f6dd8**)((char*)obj + 0x28);
    while (node != NULL) {
        int v = node->f4;
        Node021f6dd8* next = node->next;
        int sum = v + amt;
        node = next;
        if (node == NULL) {
            return v;
        }
        if ((unsigned int)sum <= (unsigned int)node->f0) {
            return v;
        }
    }
    return 0;
}
