#include <globaldefs.h>

struct HeadNode02046b24 {
    signed char id;
};

// Part of the intrusive list library at 0x02046908-0x02046c98; the config name for 0x02046b08
// is IsListEmpty, and func_02046b60 searches the same layout - a signed char id at node+0 and
// next at node+4. Returns the head node's id, or -1 for an empty list. Callers treat the id as
// a state tag rather than an index: func_ov017_0218d0ec tests the head of the ov017 list at
// +0x36fc against 3, 4, 0xa and 0x16. What those tags mean belongs to each list, not here.
extern "C" ARM int GetListHeadId(struct HeadNode02046b24** obj) {
    struct HeadNode02046b24* node = obj[0];
    if (node != 0) {
        return node->id;
    }
    return -1;
}
