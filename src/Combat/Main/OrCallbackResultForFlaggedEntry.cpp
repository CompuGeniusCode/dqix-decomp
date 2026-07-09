#include <globaldefs.h>

struct FlaggedEntry020B3F98 {
    char pad0[0xc];
    void (*callback)(int*, struct FlaggedEntry020B3F98*, unsigned int);
    struct FlaggedEntry020B3F98* next;
    char pad14[5];
    unsigned char count;
    unsigned short flags[1];
};

// USA: func_020b3f98
ARM int OrCallbackResultForFlaggedEntry(int* out, struct FlaggedEntry020B3F98* node, unsigned int idx) {
    int local;
    int result = 0;
    *out = 0;
    do {
        if (idx < node->count) {
            unsigned short flags = node->flags[idx];
            if ((flags & 0x300) == 0x100) {
                if (node->callback != NULL) {
                    node->callback(&local, node, flags & 0xff);
                    *out = *out | local;
                    result = 1;
                }
            }
        }
        node = node->next;
    } while (node != NULL);
    return result;
}
