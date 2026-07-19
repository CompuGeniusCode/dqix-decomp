#include <globaldefs.h>

struct ListNode_02240410 {
    ListNode_02240410* next;
};

// USA: func_ov031_02240410  (semantic: GetListNodeAtBlock_02240410)
#pragma optimize_for_size off
extern "C" ARM void func_ov031_02240410(char* obj, int idx, ListNode_02240410** outNode, int* outRemainder) {
    if (idx < 0x400) {
        *outNode = NULL;
        *outRemainder = idx;
        return;
    }
    int block = (idx - 0x400) >> 9;
    int count = block - 1;
    ListNode_02240410* node = *(ListNode_02240410**)(obj + 0x1c);
    if (block != 0) {
        do {
            node = node->next;
        } while (count-- != 0);
    }
    *outNode = node;
    *outRemainder = (idx - 0x400) & 0x1ff;
}
