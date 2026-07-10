#include <globaldefs.h>

struct RangeNode020b0e6c {
    unsigned short lo;                  // 0x0
    unsigned short hi;                  // 0x2
    int field4;                         // 0x4
    struct RangeNode020b0e6c* next;     // 0x8
};

struct RangeInner020b0e6c {
    char pad[0x10];
    struct RangeNode020b0e6c* head;     // 0x10
};

struct RangeHolder020b0e6c {
    struct RangeInner020b0e6c* inner;   // 0x0
};

extern "C" int func_020b0d80(struct RangeNode020b0e6c*, unsigned int);

// USA: func_020b0e6c
ARM int FindValueInRangeList(struct RangeHolder020b0e6c* obj, unsigned int key) {
    struct RangeNode020b0e6c* node = obj->inner->head;
    if (node != NULL) {
        do {
            if (node->lo <= key && key <= node->hi) {
                return func_020b0d80(node, key);
            }
            node = node->next;
        } while (node != NULL);
    }
    return 0xffff;
}
