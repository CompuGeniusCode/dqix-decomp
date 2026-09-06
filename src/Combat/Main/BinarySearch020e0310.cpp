#include <globaldefs.h>

struct Element020e0310 {
    int a;
    int b;
};

struct Container020e0310 {
    unsigned int count : 12;
    unsigned int rest : 20;
    struct Element020e0310 *base;
};

typedef int (*KeyFunc020e0310)(struct Element020e0310 *);

// USA: func_020e0310
ARM struct Element020e0310 *BinarySearch020e0310(struct Container020e0310 *c, int key, KeyFunc020e0310 fn) {
    struct Element020e0310 *base;
    int count;
    int low;
    int high;
    int mid;
    struct Element020e0310 *elem;
    int result;

    base = c->base;
    if (base == NULL || fn == NULL) return NULL;
    count = c->count;
    if (count == 0) return NULL;
    high = count - 1;
    low = 0;
    while (low <= high) {
        mid = low + ((high - low + 1) >> 1);
        elem = base + mid;
        result = fn(elem);
        if (result == key) return elem;
        if (result > key) high = mid - 1;
        else low = mid + 1;
    }
    return NULL;
}
