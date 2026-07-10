#include <globaldefs.h>

unsigned int DisableInterrupts();
unsigned int RestoreInterrupts(unsigned int mask);

struct ListNode020d27a4 {
    struct ListNode020d27a4* next;
};
struct GlobalListState020d27a4 {
    struct ListNode020d27a4* field0;
    struct ListNode020d27a4* field4;
    struct ListNode020d27a4* head8;
};
extern struct GlobalListState020d27a4 data_02112780;

// USA: func_020d27a4
// Kept as extern "C" func_020d27a4: GetFreeNodeCount020d27e0 references this symbol.
extern "C" ARM int func_020d27a4(void) {
    unsigned int mask = DisableInterrupts();
    struct ListNode020d27a4* node = data_02112780.head8;
    int count = 0;
    if (node != NULL) {
        do {
            node = node->next;
            count++;
        } while (node != NULL);
    }
    RestoreInterrupts(mask);
    return count;
}
