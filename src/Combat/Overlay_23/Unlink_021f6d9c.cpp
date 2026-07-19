#include <globaldefs.h>

struct Node021f6d9c {
    char pad0[0x8];
    struct Node021f6d9c* prev;
    struct Node021f6d9c* next;
};

struct Owner021f6d9c {
    char pad0[0x28];
    struct Node021f6d9c* cur;
};

// USA: func_ov023_021f6d9c  (semantic: Unlink_021f6d9c)
extern "C" ARM void func_ov023_021f6d9c(struct Owner021f6d9c* owner, struct Node021f6d9c* node) {
    if (node == NULL) {
        return;
    }
    if (node == owner->cur) {
        owner->cur = node->next;
    }
    if (node->prev != NULL) {
        node->prev->next = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
}
