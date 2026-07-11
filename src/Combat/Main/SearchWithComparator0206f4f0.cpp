#include <globaldefs.h>
int GetShortAt0x8(unsigned char*);

struct BinarySearchByComparatorStruct;
typedef int (*BinarySearchByComparatorFn)(void* elem);
extern void* BinarySearchByComparator(struct BinarySearchByComparatorStruct* base, int key, BinarySearchByComparatorFn comp);


// USA: func_0206f4f0
ARM void* SearchWithComparator0206f4f0(struct BinarySearchByComparatorStruct* base, int key) {
    return BinarySearchByComparator(base, key, (BinarySearchByComparatorFn)GetShortAt0x8);
}
