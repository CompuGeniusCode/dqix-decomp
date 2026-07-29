#include <globaldefs.h>

int TriggerAndPollRegister04fff200(void);
struct ListNode020d28a8;
struct ListNode020d28a8* PopReadyListNode(void);
int GetFreeNodeCount020d27e0(void);
extern "C" int func_020d22f4(int);
extern "C" void func_020d24c4(int);
void WaitUntilChannel7Ready(void);

// USA: func_020d2404
ARM int PollAndDispatchReadyNode_020d2404(int flag) {
    struct ListNode020d28a8* node;
    if (TriggerAndPollRegister04fff200() == 0) return 0;
    node = PopReadyListNode();
    if (node != 0) return (int)node;
    if (!(flag & 1)) return 0;
    if (GetFreeNodeCount020d27e0() > 0) {
        while (func_020d22f4(0) != 0) {
        }
        node = PopReadyListNode();
        if (node != 0) return (int)node;
    } else {
        func_020d24c4(1);
    }
    WaitUntilChannel7Ready();
    do {
        func_020d22f4(1);
        node = PopReadyListNode();
    } while (node == 0);
    return (int)node;
}
