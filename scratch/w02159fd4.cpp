#include <globaldefs.h>

struct AppendNode02159fd4 { char pad[0x3c]; void* next; };

void* FindFreeSlotAndReset_02159eb0(void* obj);

// USA: func_ov001_02159fd4
ARM void* AppendToTailList_02159fd4(char* obj) {
    AppendNode02159fd4* node = (AppendNode02159fd4*)FindFreeSlotAndReset_02159eb0(obj);
    if (node == NULL) return NULL;
    AppendNode02159fd4** tail = (AppendNode02159fd4**)(obj + 0x34);
    if (*tail != NULL) (*tail)->next = node;
    *tail = node;
    node->next = NULL;
    AppendNode02159fd4** head = (AppendNode02159fd4**)(obj + 0x30);
    if (*head == NULL) *head = node;
    return node;
}
