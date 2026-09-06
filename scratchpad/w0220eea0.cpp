#include <globaldefs.h>

int GetData0224e53c_0220d60c(void);

struct Node0220eea0 {
    unsigned char pad0[4];
    unsigned int field4;
    Node0220eea0* prev;
    Node0220eea0* next;
};

struct ListHeader0220eea0 {
    int count0;
    Node0220eea0* head;
    Node0220eea0* tail;
};

// USA: func_ov031_0220eea0
extern "C" ARM void func_ov031_0220eea0(void* entry) {
    Node0220eea0* node = (Node0220eea0*)entry;
    char* data = (char*)GetData0224e53c_0220d60c();
    ListHeader0220eea0* list = *(ListHeader0220eea0**)(data + 0x2270);
    if (node == 0 || list == 0) return;
    unsigned int cnt = *(unsigned int*)(data + 0x2274);
    if (cnt <= 0xc) return;
    Node0220eea0* cur = list->head;
    if (cur != 0) {
        do {
            if (cur == node) {
                Node0220eea0* prev = cur->prev;
                Node0220eea0* next = cur->next;
                if (prev != 0) prev->next = next; else list->head = next;
                next = cur->next;
                prev = cur->prev;
                if (next != 0) next->prev = prev; else list->tail = prev;
                break;
            }
            cur = cur->next;
        } while (cur != 0);
    }
    node->next = 0;
    node->prev = list->tail;
    list->tail = node;
    Node0220eea0* oldtail = node->prev;
    if (oldtail != 0) oldtail->next = node; else list->head = node;
    if (cur != 0) return;
    node->field4 = list->count0;
    list->count0 = list->count0 + 1;
}
