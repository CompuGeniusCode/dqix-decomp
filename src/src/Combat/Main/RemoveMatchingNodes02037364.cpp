#include <globaldefs.h>

void ResetStreamContext02037138(unsigned char* obj);

struct Node02037364 {
    unsigned int flag0 : 1;
    unsigned int id : 8;
    unsigned int rest : 23;
    char pad[0x28 - 4];
    struct Node02037364* next;
};

struct Container02037364 {
    char pad0[0xc];
    struct Node02037364* head;
};

// USA: func_02037364
ARM void RemoveMatchingNodes02037364(struct Container02037364* obj, int key) {
    struct Node02037364* cur;
    struct Node02037364* prev;
    struct Node02037364* head = obj->head;
    if (head == 0) {
        return;
    }
    ResetStreamContext02037138((unsigned char*)obj);
    head = obj->head;
    if ((int)head->id == key) {
        obj->head = head->next;
        return;
    }
    prev = head;
    cur = head->next;
    while (cur != 0) {
        if ((int)cur->id == key) {
            prev->next = cur->next;
        } else {
            prev = cur;
        }
        cur = cur->next;
    }
}
