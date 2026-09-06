#include <globaldefs.h>

struct Element02079f20 {
    int a;
    int b;
};

struct Container02079f20 {
    unsigned int count : 12;
    unsigned int rest : 20;
    struct Element02079f20* base;
};

typedef int (*KeyFunc02079f20)(struct Element02079f20*);

// USA: func_02079f20
ARM struct Element02079f20* BinarySearch02079f20(struct Container02079f20* c, int key, KeyFunc02079f20 fn) {
    struct Element02079f20* base;
    int count;
    int low;
    int high;
    int mid;
    struct Element02079f20* elem;
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
