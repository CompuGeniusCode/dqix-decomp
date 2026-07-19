#include <globaldefs.h>

struct ListNode0220713c { unsigned char pad[0x7c]; ListNode0220713c* next; };
struct ListHead0220713c { ListNode0220713c* head; };

extern "C" ListNode0220713c** func_ov031_0220713c(ListHead0220713c* list, ListNode0220713c* target);

// USA: func_ov031_02207120  (semantic: UnlinkNode_02207120)
extern "C" ARM ListNode0220713c** func_ov031_02207120(ListHead0220713c* list, ListNode0220713c* target) {
    ListNode0220713c** link = func_ov031_0220713c(list, target);
    if (link != NULL) {
        *link = target->next;
    }
    return link;
}
