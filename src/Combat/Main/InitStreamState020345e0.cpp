#include <globaldefs.h>

struct StreamState020345e0 {
    void* list1;             // 0x0
    unsigned short a1;       // 0x4
    unsigned short a2;       // 0x6
    void* list2;             // 0x8
    unsigned short b1;       // 0xc
    unsigned short b2;       // 0xe
    void* list3;             // 0x10
    unsigned short c1;       // 0x14
    unsigned short c2;       // 0x16
    unsigned short d;        // 0x18
    unsigned short pad;      // 0x1a
    unsigned int e;          // 0x1c
};

// USA: func_020345e0
ARM void InitStreamState020345e0(struct StreamState020345e0* self) {
    self->list1 = NULL;
    self->a1 = 0;
    self->a2 = 0;
    self->list2 = NULL;
    self->b1 = 0;
    self->b2 = 0;
    self->list3 = NULL;
    self->c1 = 0;
    self->c2 = 0;
    self->d = 0xffff;
    self->e = 0;
}
