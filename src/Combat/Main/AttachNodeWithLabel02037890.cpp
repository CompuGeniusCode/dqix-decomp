#include <globaldefs.h>

struct Struct0207ea38;
struct ListNode0x2037858;
int CopyStringToField0207ea38(struct Struct0207ea38* obj, char* str);
void AttachToList0x2037858(struct ListNode0x2037858* node, struct ListNode0x2037858* list, short id);

struct Node02037890 {
    char pad0[0x8];
    void* field_8;
    char pad1[0x86];
    short field_92;
    int field_94;
};

// USA: func_02037890
ARM void AttachNodeWithLabel02037890(struct Node02037890* node, struct Node02037890* src, char* str) {
    if (node->field_94 != 0) return;
    if (str != 0) {
        if (src->field_8 == 0) return;
        node->field_92 = CopyStringToField0207ea38((struct Struct0207ea38*)src->field_8, str);
    }
    AttachToList0x2037858((struct ListNode0x2037858*)node, (struct ListNode0x2037858*)src, node->field_92);
}
