#include <globaldefs.h>

extern "C" void func_020555a0(void* node);

struct Node020579ec {
    char pad[0x1ec];
    Node020579ec* next;  // 0x1ec
};

// USA: func_020579ec
ARM void ForEachNode020579ec(Node020579ec** pp) {
    Node020579ec* n = *pp;
    while (n != NULL) {
        func_020555a0(n);
        n = n->next;
    }
}
