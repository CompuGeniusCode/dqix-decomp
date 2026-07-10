#include <globaldefs.h>

unsigned int DisableInterrupts(void);
unsigned int RestoreInterrupts(unsigned int mask);
extern "C" void func_020c78e8(void* p);

struct Node020cb034 {
    struct Node020cb034* prev;
    struct Node020cb034* next;
    int f8;
    unsigned int fc;
    int f10;
    int f14;
    int f18;
};

// USA: func_020cb034
ARM void UnlinkAndResetNode020cb034(struct Node020cb034* node, int value) {
    unsigned int mask;
    struct Node020cb034* prev;
    struct Node020cb034* next;
    mask = DisableInterrupts();
    prev = node->prev;
    next = node->next;
    if (prev != NULL) {
        prev->next = next;
    }
    if (next != NULL) {
        next->prev = prev;
    }
    node->prev = NULL;
    node->next = NULL;
    node->fc &= ~0x4f;
    node->f14 = value;
    func_020c78e8(&node->f18);
    RestoreInterrupts(mask);
}
