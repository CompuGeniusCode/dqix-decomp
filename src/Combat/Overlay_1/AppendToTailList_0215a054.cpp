#include <globaldefs.h>

struct AppendNode0215a054 { char pad[0x3c]; void* next; };

void* FindFreeSlotAndReset_02159eb0(void* obj);

// USA: func_ov001_0215a054  (semantic: AppendToTailList_0215a054)
extern "C" ARM void* func_ov001_0215a054(char* obj) {
    AppendNode0215a054* node = (AppendNode0215a054*)FindFreeSlotAndReset_02159eb0(obj);
    if (node == NULL) return NULL;
    AppendNode0215a054** tail = (AppendNode0215a054**)(obj + 0x44);
    if (*tail != NULL) (*tail)->next = node;
    *tail = node;
    node->next = NULL;
    AppendNode0215a054** head = (AppendNode0215a054**)(obj + 0x40);
    if (*head == NULL) *head = node;
    return node;
}
