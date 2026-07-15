#include <globaldefs.h>

struct Node02181c94 {
    char pad0[0xe];
    short val;
    char pad1[0x10];
    struct Node02181c94* next;
};
struct Obj02181c94 {
    char pad0[0x14];
    struct Node02181c94* head;
};

// USA: func_ov000_02181c94
ARM int CollectListShorts02181c94(void* unused, struct Obj02181c94* obj, int* outArray) {
    struct Node02181c94* node = obj->head;
    int count = 0;
    while (node) {
        outArray[count] = node->val;
        node = node->next;
        count++;
    }
    return count;
}
