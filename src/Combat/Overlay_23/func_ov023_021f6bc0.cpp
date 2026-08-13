#include <globaldefs.h>

struct NodeF6bc0 {
    char pad0[0x18];
    NodeF6bc0* next;
    int state;
};

struct ObjF6bc0 {
    NodeF6bc0* head;
};

// USA: func_ov023_021f6bc0
extern "C" ARM int func_ov023_021f6bc0(ObjF6bc0* obj) {
    for (NodeF6bc0* n = obj->head; n != 0; n = n->next) {
        if (n->state != 2) return 1;
    }
    return 0;
}
