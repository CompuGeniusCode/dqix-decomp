#include <globaldefs.h>

struct Node02181c6c {
    char pad0[0x20];
    unsigned short val;
    char pad1[0xe];
    struct Node02181c6c* next;
};
struct Obj02181c6c {
    char pad0[0x10];
    struct Node02181c6c* head;
};

// USA: func_ov000_02181c6c
ARM int CollectListShorts02181c6c(void* unused, struct Obj02181c6c* obj, int* outArray) {
    struct Node02181c6c* node = obj->head;
    int count = 0;
    while (node) {
        outArray[count] = node->val;
        node = node->next;
        count++;
    }
    return count;
}
