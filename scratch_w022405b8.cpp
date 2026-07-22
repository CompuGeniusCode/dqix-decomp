#include <globaldefs.h>

struct ListNode_02240410;
extern "C" void func_ov031_02240410(char* obj, int idx, ListNode_02240410** outNode, int* outRemainder);
extern "C" signed char func_ov031_0224046c(void* obj, void** chain, int* counter);

// USA: func_ov031_022405b8
#pragma optimize_for_size off
extern "C" ARM int func_ov031_022405b8(char* obj, int start, int end) {
    if (start >= end) goto ret_neg1;
    {
        ListNode_02240410* node;
        int counter;
        func_ov031_02240410(obj, start, &node, &counter);
        if (start >= end) goto ret_neg1;
        do {
            if (func_ov031_0224046c(obj, (void**)&node, &counter) != 0x20) {
                return start;
            }
            start++;
        } while (start < end);
    }
ret_neg1:
    return -1;
}
