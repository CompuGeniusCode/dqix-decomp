#include <globaldefs.h>

struct AppendNode0215a014 { char pad[0x3c]; void* next; };

void* FindFreeSlotAndReset_02159eb0(void* obj);

// USA: func_ov001_0215a014  (semantic: AppendToTailList_0215a014)
extern "C" ARM void* func_ov001_0215a014(char* obj) {
    AppendNode0215a014* node = (AppendNode0215a014*)FindFreeSlotAndReset_02159eb0(obj);
    if (node == NULL) return NULL;
    AppendNode0215a014** tail = (AppendNode0215a014**)(obj + 0x3c);
    if (*tail != NULL) (*tail)->next = node;
    *tail = node;
    node->next = NULL;
    AppendNode0215a014** head = (AppendNode0215a014**)(obj + 0x38);
    if (*head == NULL) *head = node;
    return node;
}
