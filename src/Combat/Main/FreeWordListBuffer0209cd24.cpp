#include <globaldefs.h>
class AllocatorUnion;
void TailForward02012da4(AllocatorUnion*, void*);

extern int data_02114e20;

struct WordList0209cbb8 {
    int* buffer;
    unsigned char count;
    unsigned char capacity;
};
void ResetWordList0209cbb8(struct WordList0209cbb8*);

// USA: func_0209cd24
ARM void FreeWordListBuffer0209cd24(struct WordList0209cbb8* list) {
    if (list->buffer != NULL) {
        TailForward02012da4((AllocatorUnion*)(&data_02114e20), (void*)(list->buffer));
    }
    ResetWordList0209cbb8(list);
}
