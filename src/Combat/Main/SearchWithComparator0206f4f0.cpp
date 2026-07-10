#include <globaldefs.h>

struct BinarySearchByComparatorStruct;
typedef int (*BinarySearchByComparatorFn)(void* elem);
extern void* BinarySearchByComparator(struct BinarySearchByComparatorStruct* base, int key, BinarySearchByComparatorFn comp);

extern "C" int func_0206ef40(void* elem);

// USA: func_0206f4f0
ARM void* SearchWithComparator0206f4f0(struct BinarySearchByComparatorStruct* base, int key) {
    return BinarySearchByComparator(base, key, func_0206ef40);
}
