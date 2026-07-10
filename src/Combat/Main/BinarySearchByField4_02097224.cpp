#include <globaldefs.h>

struct BinarySearch020971a8Node;
struct BinarySearch020971a8Container;
typedef int (*BinarySearch020971a8Cmp)(struct BinarySearch020971a8Node*);
struct BinarySearch020971a8Node* BinarySearch020971a8(struct BinarySearch020971a8Container*, int, BinarySearch020971a8Cmp);
extern "C" int func_02096f78(struct BinarySearch020971a8Node*);

// USA: func_02097224
ARM struct BinarySearch020971a8Node* BinarySearchByField4_02097224(struct BinarySearch020971a8Container* c, int key) {
    return BinarySearch020971a8(c, key, func_02096f78);
}
