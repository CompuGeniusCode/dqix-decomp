#include <globaldefs.h>

struct Node02095910 { unsigned char pad[0x28]; void* link; };
struct Owner02095910 { unsigned char pad[0xa4]; struct Node02095910* slot; };

// USA: func_02095910
ARM void SetSlotA4(struct Owner02095910* owner, struct Node02095910* node) {
    struct Node02095910* old = owner->slot;
    owner->slot = node;
    if (old != NULL) {
        node->link = old;
    }
}
