#include <globaldefs.h>

struct FlaggedEntry020B3AD0 {
    char pad0[0xc];
    void (*callback)(void*, struct FlaggedEntry020B3AD0*, unsigned int);
    struct FlaggedEntry020B3AD0* next;
    char pad14[5];
    unsigned char count;
    unsigned short flags[1];
};

// USA: func_020b3ad0
ARM int InvokeCallbackForFlaggedEntry(void* ctx, struct FlaggedEntry020B3AD0* node, unsigned int idx) {
    int result = 0;
    if (node == NULL) return 0;
    do {
        if (idx < node->count) {
            unsigned short flags = node->flags[idx];
            if ((flags & 0x300) == 0x100) {
                if (node->callback != NULL) {
                    node->callback(ctx, node, flags & 0xff);
                    result = 1;
                }
            }
        }
        node = node->next;
    } while (node != NULL);
    return result;
}
