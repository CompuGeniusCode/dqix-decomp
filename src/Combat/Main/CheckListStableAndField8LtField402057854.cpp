#include <globaldefs.h>

struct ListNode02057854 {
    char pad0[0x4];
    unsigned int field4;
    unsigned int field8;
    unsigned char byteC;
    char pad_d[0x34 - 0xd];
    struct ListNode02057854* head34;
    unsigned char byte38;
    unsigned char byte39;
    char pad_3a[0x148 - 0x3a];
    struct ListNode02057854* next148;
};

// USA: func_02057854
ARM int CheckListStableAndField8LtField402057854(struct ListNode02057854* node) {
    struct ListNode02057854* child;
    if (node->byteC != 0) return 0;
    if (node->byte39 != 0) return 0;
    if (node->byte38 == 0) {
        for (child = node->head34; child != 0; child = child->next148) {
            int ok;
            if (child->byteC != 0) {
                ok = 0;
            } else {
                ok = child->field8 <= child->field4;
            }
            if (!ok) return 0;
        }
    }
    return node->field8 < node->field4;
}
