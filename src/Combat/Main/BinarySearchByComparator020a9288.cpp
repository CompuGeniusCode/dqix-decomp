#include <globaldefs.h>

typedef int (*CmpFn020a9288)(void*);

struct Obj020a9288 {
    unsigned int count : 12;
    char* arr;
};

// USA: func_020a9288
ARM void* BinarySearchByComparator020a9288(struct Obj020a9288* obj, int key, CmpFn020a9288 cmp) {
    char* arr = obj->arr;
    int count;
    int lo, hi, mid, r;
    if (arr == 0 || cmp == 0) {
        return 0;
    }
    count = obj->count;
    if (count == 0) {
        return 0;
    }
    lo = 0;
    hi = count - 1;
    while (lo <= hi) {
        mid = lo + ((hi - lo + 1) >> 1);
        r = cmp(arr + mid * 64);
        if (r == key) {
            return arr + mid * 64;
        }
        if (r > key) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return 0;
}
