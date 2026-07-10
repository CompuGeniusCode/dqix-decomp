#include <globaldefs.h>

struct SortNode020976e0 { struct SortNode020976e0* next; char pad[0xa]; short key; };
extern "C" struct SortNode020976e0* func_02097720(void* c, int key);

// USA: func_020976e0
ARM void BuildSortedChain020976e0(void* c) {
    struct SortNode020976e0* p = *(struct SortNode020976e0**)c = func_02097720(c, -1);
    if (p == 0) return;
    while (p != 0) {
        struct SortNode020976e0* next = func_02097720(c, p->key);
        p->next = next;
        p = next;
    }
}
