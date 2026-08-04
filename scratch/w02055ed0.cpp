#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct02058c88;
void InitStruct02058c88(struct Struct02058c88* obj);

struct Node055ed0 {
    char pad0[0x2c];
    unsigned char flag2c;
    char pad2d[0x148 - 0x2d];
    struct Node055ed0* next;
};

struct Self055ed0 {
    char pad0[0x28];
    SafeAllocator* allocator;
    char pad2c[0x34 - 0x2c];
    struct Node055ed0* head;
};

// USA: func_02055ed0
ARM struct Node055ed0* FindOrAllocateNode02055ed0(struct Self055ed0* self) {
    struct Node055ed0** link = &self->head;
    struct Node055ed0* node;
    while ((node = *link) != 0) {
        if (node->flag2c == 0) {
            return node;
        }
        link = &node->next;
    }
    struct Node055ed0* newNode = 0;
    if (self->allocator == 0) {
        return newNode;
    }
    newNode = (struct Node055ed0*)self->allocator->Allocate(sizeof(struct Node055ed0));
    if (newNode == 0) {
        return 0;
    }
    InitStruct02058c88((struct Struct02058c88*)newNode);
    newNode->next = 0;
    InitStruct02058c88((struct Struct02058c88*)newNode);
    newNode->next = 0;
    *link = newNode;
    return newNode;
}
