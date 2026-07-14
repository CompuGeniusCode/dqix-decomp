#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Obj020553ac;
void InitStruct020553ac(struct Obj020553ac* obj);
extern "C" int func_020553ec(void* obj, int a1, void* alloc, int a2, int a3);

struct Node02057de0 {
    unsigned char pad[0x1ec];
    struct Node02057de0* next;
};

struct NodeList02057de0 {
    struct Node02057de0* head;
    int count;
};

// USA: func_02057de0
ARM int CreateAndRegisterNode02057de0(NodeList02057de0* list, int a1, SafeAllocator* alloc, int a2, int a3) {
    Node02057de0* node = (Node02057de0*)alloc->Allocate(0x1f0);
    if (node == NULL) return -1;
    InitStruct020553ac((struct Obj020553ac*)node);
    if (func_020553ec(node, a1, alloc, a2, a3) == 0) return -1;
    Node02057de0** slot = &list->head;
    while (*slot != NULL) slot = &(*slot)->next;
    *slot = node;
    return list->count++;
}
