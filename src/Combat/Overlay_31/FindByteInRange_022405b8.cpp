#include <globaldefs.h>

struct ListNode_02240410 { ListNode_02240410* next; };
extern "C" void func_ov031_02240410(char* obj, int idx, ListNode_02240410** outNode, int* outRemainder);
extern "C" signed char func_ov031_0224046c(void* obj, void** chain, int* counter);

// USA: func_ov031_022405b8  (semantic: FindByteInRange_022405b8)
#pragma optimize_for_size off
extern "C" ARM int func_ov031_022405b8(char* obj, int start, int end) {
    if (start >= end) {
        goto fail;
    }
    {
        ListNode_02240410* node;
        int remainder;
        func_ov031_02240410(obj, start, &node, &remainder);
        if (start >= end) {
            goto fail;
        }
        int i = start;
        do {
            signed char c = func_ov031_0224046c(obj, (void**)&node, &remainder);
            if (c != 0x20) {
                return i;
            }
            i++;
        } while (i < end);
    }
fail:
    return -1;
}
