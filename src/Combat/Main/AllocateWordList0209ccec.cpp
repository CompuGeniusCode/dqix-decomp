#include <globaldefs.h>

class AllocatorUnion;
void* AllocateAligned4(AllocatorUnion*, unsigned int);
extern AllocatorUnion data_02114e20;

struct WordList0209ccec {
    int* buffer;         // 0x0
    unsigned char index; // 0x4
    unsigned char count; // 0x5
};

// USA: func_0209ccec
ARM void AllocateWordList0209ccec(struct WordList0209ccec* list, int count) {
    if (count <= 0) return;
    list->buffer = (int*)AllocateAligned4(&data_02114e20, count << 2);
    list->count = count;
    list->index = 0;
}
