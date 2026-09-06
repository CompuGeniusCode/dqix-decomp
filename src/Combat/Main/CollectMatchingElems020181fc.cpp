#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct SubElem_020181fc {
    char pad[0x24];
    void* state;
    char pad2[0x70 - 0x24 - 4];
};

struct ListNode_020181fc {
    char pad0[0x14];
    int count;
    char pad1[0x44 - 0x14 - 4];
    SubElem_020181fc* elems;
    char pad2[0x54 - 0x44 - 4];
    ListNode_020181fc* next;
};

// USA: func_020181fc
ARM void CollectMatchingElems020181fc(void* obj) {
    char* base = (char*)obj;
    *(int*)(base + 0x82c) = 0;
    if (*(unsigned char*)(base + 0x2000 + 0x3b8) != 0) {
        *(int*)(base + 0x82c) = 0x101;
        return;
    }

    ListNode_020181fc* node = *(ListNode_020181fc**)(base + 0x41c);
    while (node != NULL) {
        int count = node->count;
        for (int i = 0; i < count; i++) {
            SubElem_020181fc* elem = &node->elems[i];
            void* state = elem->state;
            if (state != NULL && *(short*)state == 1) {
                (*(int*)(base + 0x82c))++;
            }
        }
        node = node->next;
    }

    SafeAllocator* alloc = *(SafeAllocator**)(base + 0x68);
    void* arr = alloc->Allocate(*(unsigned int*)(base + 0x82c) * 4);
    *(void**)(base + 0x824) = arr;

    int idx = 0;
    node = *(ListNode_020181fc**)(base + 0x41c);
    while (node != NULL) {
        int count = node->count;
        for (int i = 0; i < count; i++) {
            SubElem_020181fc* elem = &node->elems[i];
            void* state = elem->state;
            if (state != NULL && *(short*)state == 1) {
                ((void**)*(void**)(base + 0x824))[idx] = elem;
                idx++;
            }
        }
        node = node->next;
    }
}
