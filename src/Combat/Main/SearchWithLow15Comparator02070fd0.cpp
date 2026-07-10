#include <globaldefs.h>

struct Struct020709c8;
extern int GetLow15BitField020709c8(struct Struct020709c8* p);

struct Element02070e60;
struct Container02070e60;
typedef int (*CompareCallback02070e60)(struct Element02070e60*);
extern struct Element02070e60* BinarySearch02070e60(struct Container02070e60* container, int key, CompareCallback02070e60 compare);

// USA: func_02070fd0
ARM struct Element02070e60* SearchWithLow15Comparator02070fd0(struct Container02070e60* container, int key) {
    return BinarySearch02070e60(container, key, (CompareCallback02070e60)GetLow15BitField020709c8);
}
