#include <globaldefs.h>

typedef int (*CmpFn021892d4)(void*);

struct SearchList021892d4 {
    unsigned short count;
    char pad[0xc - 2];
    void** arr;
};

// USA: func_ov014_021892d4  (semantic: BinarySearchByCallback_021892d4)
extern "C" ARM void* func_ov014_021892d4(struct SearchList021892d4* list, int key, CmpFn021892d4 cmp) {
    void** arr = list->arr;
    if (arr == 0 || cmp == 0) {
        return 0;
    }
    if (list->count == 0) {
        return 0;
    }
    int lo = 0;
    int hi = list->count - 1;
    while (lo <= hi) {
        int mid = lo + ((hi - lo + 1) >> 1);
        void** elem = arr + mid;
        int val = cmp(elem);
        if (val == key) {
            return elem;
        }
        if (val > key) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return 0;
}
