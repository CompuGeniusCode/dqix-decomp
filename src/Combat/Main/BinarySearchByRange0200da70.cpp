#include <globaldefs.h>

struct Entry0200da70 {
    unsigned int key;
    unsigned int sizeFlag;
    int pad8;
};

// USA: func_0200da70  (semantic: BinarySearchByRange0200da70)
extern "C" ARM void* func_0200da70(struct Entry0200da70* arr, int count, unsigned int target) {
    int lo = 0;
    int hi = count - 1;
    if (hi < 0) goto notfound;
    do {
        int mid = (lo + hi) >> 1;
        struct Entry0200da70* e = &arr[mid];
        if (target < e->key) {
            hi = mid - 1;
        } else {
            unsigned int end = e->key + (e->sizeFlag & ~1);
            if (target > end) {
                lo = mid + 1;
            } else {
                return e;
            }
        }
    } while (lo <= hi);
notfound:
    return 0;
}
