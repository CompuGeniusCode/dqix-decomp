#include <globaldefs.h>

struct ListNode020378dc;
void UnlinkOrClearListNode020378dc(struct ListNode020378dc* node);
void ResetStreamContext02037138(unsigned char* obj);

// USA: func_02037330
ARM void ResetAndUnlinkNode02037330(unsigned char* obj) {
    UnlinkOrClearListNode020378dc((struct ListNode020378dc*)obj);
    UnlinkOrClearListNode020378dc((struct ListNode020378dc*)obj);
    *(int*)(obj + 0xa8) = 0;
    *(int*)(obj + 8) = 0;
    ResetStreamContext02037138(obj);
    *(int*)(obj + 0xc) = 0;
}
