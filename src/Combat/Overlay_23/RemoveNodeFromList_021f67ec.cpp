#include <globaldefs.h>

struct Node021f67ec {
    virtual void R0();
    virtual void R1();
    virtual void R2();
    virtual void R3();
    virtual void R4();
    virtual void R5();
    virtual void OnRemoved(void* head);
    char pad4[0x14 - 4];
    struct Node021f67ec* prev;
    struct Node021f67ec* next;
};

struct ListHead021f67ec {
    struct Node021f67ec* first;
};

// USA: func_ov023_021f67ec  (semantic: RemoveNodeFromList_021f67ec)
extern "C" ARM void func_ov023_021f67ec(struct ListHead021f67ec* head, struct Node021f67ec* node) {
    if (!node) return;
    struct Node021f67ec* prev = node->prev;
    struct Node021f67ec* next = node->next;
    if (prev) prev->next = next;
    if (next) next->prev = prev;
    if (head->first == node) head->first = next;
    node->prev = 0;
    node->next = 0;
    node->OnRemoved(head);
}
