#include <globaldefs.h>

typedef int (*Comparator020dfb48)(void *elem);

struct Element020dfb48 {
    int a;
    int b;
};

struct Container020dfb48 {
    unsigned short count;
    unsigned short pad2;
    int pad4;
    struct Element020dfb48 *arr;
};

// USA: func_020dfb48
ARM void *BinarySearchByComparator020dfb48(struct Container020dfb48 *base, int key, Comparator020dfb48 comp) {
    struct Element020dfb48 *arr;
    int count;
    int low;
    int high;
    int mid;
    int r;

    arr = base->arr;
    if (arr == NULL || comp == NULL) return NULL;
    count = base->count;
    if (count == 0) return NULL;
    low = 0;
    high = count - 1;
    while (low <= high) {
        mid = low + ((high - low + 1) >> 1);
        r = comp(&arr[mid]);
        if (r == key) return &arr[mid];
        if (r > key) high = mid - 1;
        else low = mid + 1;
    }
    return NULL;
}
