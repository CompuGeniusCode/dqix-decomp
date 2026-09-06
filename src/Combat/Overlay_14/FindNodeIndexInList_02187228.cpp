#include <globaldefs.h>

struct Node02187228 { Node02187228* next; };

int FindMappedMemberId02080468(void* a, int b);

// USA: func_ov014_02187228  (semantic: FindNodeIndexInList_02187228)
extern "C" ARM void func_ov014_02187228(char* obj, Node02187228* target) {
    *(Node02187228**)(obj + 0xbc) = *(Node02187228**)(obj + 0xb8);
    *(short*)(obj + 0x176) = 0x1b;
    void* src = *(void**)(obj + 0xc0);
    if (src != 0) {
        *(short*)(obj + 0x176) = (short)FindMappedMemberId02080468(src, 5);
    }
    if (target == 0) return;

    Node02187228* node = *(Node02187228**)(obj + 0xb8);
    Node02187228* ckpt = node;
    short idx = 0;
    Node02187228* head = *(Node02187228**)(obj + 0xb8);
    while (node != 0) {
        if (idx % 16 == 0) { ckpt = node; idx = 0; }
        if (node == target) break;
        idx = (short)(idx + 1);
        node = node->next;
    }
    if (node == 0) { idx = 0; ckpt = head; }
    *(short*)(obj + 0x176) = *(short*)(obj + 0x176) + idx;
    *(Node02187228**)(obj + 0xbc) = ckpt;
}
