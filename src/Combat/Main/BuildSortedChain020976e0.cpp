#include <globaldefs.h>
struct SortNode020976e0* FindMinValueAboveThreshold02097720(struct Header02097720*, int);

struct SortNode020976e0 { struct SortNode020976e0* next; char pad[0xa]; short key; };

// USA: func_020976e0
ARM void BuildSortedChain020976e0(void* c) {
    struct SortNode020976e0* p = *(struct SortNode020976e0**)c = FindMinValueAboveThreshold02097720((struct Header02097720*)(c), (int)(-1));
    if (p == 0) return;
    while (p != 0) {
        struct SortNode020976e0* next = FindMinValueAboveThreshold02097720((struct Header02097720*)(c), (int)(p->key));
        p->next = next;
        p = next;
    }
}
