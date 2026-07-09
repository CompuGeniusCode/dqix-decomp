#include <globaldefs.h>

struct SearchElem02030a24 {
    int key;
    int value;
};

struct SearchTable02030a24 {
    int count;
    struct SearchElem02030a24* elems;
};

// USA: func_02030a24
ARM struct SearchElem02030a24* BinarySearchByKey02030a24(struct SearchTable02030a24* table, int key) {
    int lo;
    int hi;
    int mid;
    struct SearchElem02030a24* e;
    if (table->count <= 0) {
        return 0;
    }
    lo = 0;
    hi = table->count - 1;
    while (lo <= hi) {
        mid = lo + (hi - lo + 1) / 2;
        e = &table->elems[mid];
        if (key == e->key) {
            return e;
        }
        if (key < e->key) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return 0;
}
