#include <globaldefs.h>

struct Node020958fc { unsigned char pad[0xc]; void* link; };
struct Owner020958fc { unsigned char pad[0xa0]; struct Node020958fc* slot; };

// USA: func_020958fc
ARM void SetSlotA0(struct Owner020958fc* owner, struct Node020958fc* node) {
    struct Node020958fc* old = owner->slot;
    owner->slot = node;
    if (old != NULL) {
        node->link = old;
    }
}
