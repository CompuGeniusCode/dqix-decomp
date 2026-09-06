#include <globaldefs.h>

struct AppendNode02159f54 { char pad[0x3c]; void* next; };

void* FindFreeSlotAndReset_02159eb0(void* obj);

// USA: func_ov001_02159f54  (semantic: AppendToTailList_02159f54)
extern "C" ARM void* func_ov001_02159f54(char* obj) {
    AppendNode02159f54* node = (AppendNode02159f54*)FindFreeSlotAndReset_02159eb0(obj);
    if (node == NULL) return NULL;
    AppendNode02159f54** tail = (AppendNode02159f54**)(obj + 0x14);
    if (*tail != NULL) (*tail)->next = node;
    *tail = node;
    node->next = NULL;
    AppendNode02159f54** head = (AppendNode02159f54**)(obj + 0x10);
    if (*head == NULL) *head = node;
    return node;
}
