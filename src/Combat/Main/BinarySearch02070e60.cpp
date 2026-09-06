#include <globaldefs.h>

struct Element02070e60 {
    unsigned char data[0x84];
};

struct Container02070e60 {
    unsigned int count : 12;
    struct Element02070e60 *elements;
};

typedef int (*CompareCallback02070e60)(struct Element02070e60 *);

// USA: func_02070e60
ARM struct Element02070e60 *BinarySearch02070e60(struct Container02070e60 *container, int key, CompareCallback02070e60 compare) {
    struct Element02070e60 *elements = container->elements;
    int count;
    int lo, hi;
    if (elements == NULL || compare == NULL) return NULL;
    count = container->count;
    if (count == 0) return NULL;
    lo = 0;
    hi = count - 1;
    while (lo <= hi) {
        int mid = lo + ((hi - lo + 1) >> 1);
        struct Element02070e60 *e = elements + mid;
        int r = compare(e);
        if (r == key) return e;
        if (r > key) hi = mid - 1;
        else lo = mid + 1;
    }
    return NULL;
}
