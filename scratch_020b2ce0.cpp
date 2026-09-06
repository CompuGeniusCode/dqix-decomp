#include <globaldefs.h>

struct NodeC78;
struct NodeBC0;

extern void SetBitsForFlaggedEntries020b2c78(unsigned int* bitset, NodeC78* node);
extern void InsertNodeSorted020b2bc0(NodeBC0** list, NodeBC0* n);

// USA: func_020b2ce0
ARM void DispatchNodeByCategory020b2ce0(void* self, void* node) {
    unsigned char* tag;
    if (node == 0 || (tag = *(unsigned char**)((char*)node + 8)) == 0) {
        return;
    }
    switch (*tag) {
    case 'M':
        SetBitsForFlaggedEntries020b2c78((unsigned int*)((char*)self + 0x3c), (NodeC78*)node);
        InsertNodeSorted020b2bc0((NodeBC0**)((char*)self + 0x8), (NodeBC0*)node);
        break;
    case 'J':
        SetBitsForFlaggedEntries020b2c78((unsigned int*)((char*)self + 0x44), (NodeC78*)node);
        InsertNodeSorted020b2bc0((NodeBC0**)((char*)self + 0x10), (NodeBC0*)node);
        break;
    case 'V':
        SetBitsForFlaggedEntries020b2c78((unsigned int*)((char*)self + 0x4c), (NodeC78*)node);
        InsertNodeSorted020b2bc0((NodeBC0**)((char*)self + 0x18), (NodeBC0*)node);
        break;
    }
}
