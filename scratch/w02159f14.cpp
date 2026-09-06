#include <globaldefs.h>

struct AppendNode02159f14 { char pad[0x3c]; void* next; };

void* FindFreeSlotAndReset_02159eb0(void* obj);

// USA: func_ov001_02159f14
ARM void* AppendToTailList_02159f14(char* obj) {
    AppendNode02159f14* node = (AppendNode02159f14*)FindFreeSlotAndReset_02159eb0(obj);
    if (node == NULL) return NULL;
    AppendNode02159f14** tail = (AppendNode02159f14**)(obj + 0xc);
    if (*tail != NULL) (*tail)->next = node;
    *tail = node;
    node->next = NULL;
    AppendNode02159f14** head = (AppendNode02159f14**)(obj + 0x8);
    if (*head == NULL) *head = node;
    return node;
}
