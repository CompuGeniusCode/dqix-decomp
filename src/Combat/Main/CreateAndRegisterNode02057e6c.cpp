#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Obj020553ac;
void InitStruct020553ac(struct Obj020553ac* obj);
struct Obj02055558;
int InitStructWithParams02055558(struct Obj02055558* obj, int a2, int a3, int a4, int a5, int a6);

struct Node02057e6c {
    unsigned char pad[0x1ec];
    struct Node02057e6c* next;
};

struct NodeList02057e6c {
    struct Node02057e6c* head;
    int count;
};

// USA: func_02057e6c  (semantic: CreateAndRegisterNode02057e6c)
extern "C" ARM int func_02057e6c(NodeList02057e6c* list, int p1, SafeAllocator* alloc, int p2, int p3, int p4) {
    Node02057e6c* node = (Node02057e6c*)alloc->Allocate(0x1f0);
    if (node == NULL) return -1;
    InitStruct020553ac((struct Obj020553ac*)node);
    if (InitStructWithParams02055558((struct Obj02055558*)node, p1, (int)alloc, p2, p3, p4) == 0) return -1;
    Node02057e6c** slot = &list->head;
    while (*slot != NULL) slot = &(*slot)->next;
    *slot = node;
    return list->count++;
}
