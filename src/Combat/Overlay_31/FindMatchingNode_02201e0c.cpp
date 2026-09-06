#include <globaldefs.h>

struct RootStruct02201e0c { unsigned char pad[0x8]; void* head; };
struct Node02201e0c { unsigned char pad0[0x68]; Node02201e0c* next; unsigned char pad1[0xa4-0x68-4]; void* field; };

extern RootStruct02201e0c data_02111304;
extern "C" int func_ov031_02201d58(void* a, void* b, void* c);

// USA: func_ov031_02201e0c  (semantic: FindMatchingNode_02201e0c)
extern "C" ARM void* func_ov031_02201e0c(void* a, void* b) {
    int* field;
    Node02201e0c* node = (Node02201e0c*)data_02111304.head;
    if (node) {
        do {
            field = (int*)node->field;
            if (field && *field != 0) {
                if (func_ov031_02201d58(a, b, field) != 0) return field;
            }
            node = node->next;
        } while (node);
    }
    return NULL;
}
