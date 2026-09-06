#include <globaldefs.h>
struct SortNode02097628* FindMinValueAboveThreshold02097668(struct Header02097668*, int);

struct SortNode02097628 { struct SortNode02097628* next; char pad[0x16]; short key; };

// USA: func_02097628
ARM void BuildSortedChain02097628(void* c) {
    struct SortNode02097628* p = *(struct SortNode02097628**)c = FindMinValueAboveThreshold02097668((struct Header02097668*)(c), (int)(-1));
    if (p == 0) return;
    while (p != 0) {
        struct SortNode02097628* next = FindMinValueAboveThreshold02097668((struct Header02097668*)(c), (int)(p->key));
        p->next = next;
        p = next;
    }
}
