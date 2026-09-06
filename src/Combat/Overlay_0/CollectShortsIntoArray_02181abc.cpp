#include <globaldefs.h>

struct ListNode02160094 {
    char pad[0x30];
    struct ListNode02160094* next;
};

struct List02160094 {
    char pad0[8];
    unsigned char count;
    char pad1[7];
    struct ListNode02160094* head;
};
extern struct ListNode02160094* GetNodeAtIndex02160094(struct List02160094* list, int index);
extern "C" int func_ov000_0215e9fc(void* obj, short* buf, int max, int start);
extern "C" int func_ov000_0215ec1c(void* obj, short* buf, int max, int start);

// USA: func_ov000_02181abc  (semantic: CollectShortsIntoArray_02181abc)
extern "C" ARM int func_ov000_02181abc(void* obj, struct List02160094* list, int* outArray) {
    struct ListNode02160094* node = GetNodeAtIndex02160094(list, 0);
    short buf[16];
    int n1;
    int i;
    if (node == 0) {
        return 0;
    }
    n1 = 0;
    n1 = n1 + func_ov000_0215e9fc(obj, buf, 0x10, n1);
    n1 = n1 + func_ov000_0215ec1c(obj, buf + n1, 0x10 - n1, 0);
    for (i = 0; i < n1; i++) {
        outArray[i] = buf[i];
    }
    return n1;
}
