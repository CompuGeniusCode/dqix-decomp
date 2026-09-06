#include <globaldefs.h>

struct Node021e8bac {
    char pad0[1];
    unsigned char field1;
    char pad1[6];
    struct Node021e8bac* next;
};
struct Obj021e8bac {
    char pad0[0x30];
    unsigned char field0x30;
    char pad1[0x1a7];
    struct Node021e8bac* head;
};

// USA: func_ov025_021e8bac
ARM void PushLogNode021e8bac(struct Obj021e8bac* obj, struct Node021e8bac* node) {
    node->field1 = obj->field0x30;
    node->next = obj->head;
    obj->head = node;
}
