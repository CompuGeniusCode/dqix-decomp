#include <globaldefs.h>

struct SortNode02097628 { struct SortNode02097628* next; char pad[0x16]; short key; };
extern "C" struct SortNode02097628* func_02097668(void* c, int key);

// USA: func_02097628
ARM void BuildSortedChain02097628(void* c) {
    struct SortNode02097628* p = *(struct SortNode02097628**)c = func_02097668(c, -1);
    if (p == 0) return;
    while (p != 0) {
        struct SortNode02097628* next = func_02097668(c, p->key);
        p->next = next;
        p = next;
    }
}
