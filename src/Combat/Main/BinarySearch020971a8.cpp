#include <globaldefs.h>

struct BinarySearch020971a8Node { char pad[0x30]; };
struct BinarySearch020971a8Container { unsigned short count; char pad[6]; struct BinarySearch020971a8Node* base; };
typedef int (*BinarySearch020971a8Cmp)(struct BinarySearch020971a8Node*);

// USA: func_020971a8
ARM struct BinarySearch020971a8Node* BinarySearch020971a8(struct BinarySearch020971a8Container* c, int key, BinarySearch020971a8Cmp cmp) {
    struct BinarySearch020971a8Node* base = c->base;
    int lo, hi, mid, r, count;
    struct BinarySearch020971a8Node* elem;
    if (base == NULL || cmp == NULL) return NULL;
    count = c->count;
    if (count == 0) return NULL;
    hi = count - 1;
    lo = 0;
    while (lo <= hi) {
        mid = lo + ((hi - lo + 1) >> 1);
        elem = base + mid;
        r = cmp(elem);
        if (r == key) return elem;
        if (r > key) hi = mid - 1;
        else lo = mid + 1;
    }
    return NULL;
}
