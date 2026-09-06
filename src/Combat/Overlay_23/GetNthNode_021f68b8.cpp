#include <globaldefs.h>

struct Node021f68b8 { void* first; };

// USA: func_ov023_021f68b8
ARM void* GetNthNode_021f68b8(struct Node021f68b8* head, int n) {
    void* node = head->first;
    while (node != NULL && n > 0) {
        node = *(void**)((char*)node + 0x18);
        n--;
    }
    return node;
}
