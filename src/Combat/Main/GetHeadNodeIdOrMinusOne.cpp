#include <globaldefs.h>

struct HeadNode02046b24 {
    signed char id;
};

// USA: func_02046b24
ARM int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj) {
    struct HeadNode02046b24* node = obj[0];
    if (node != 0) {
        return node->id;
    }
    return -1;
}
