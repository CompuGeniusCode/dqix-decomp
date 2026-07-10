#include <globaldefs.h>

extern int data_02114e20;
extern "C" void func_02012da4(void*, void*);

struct WordList0209cbb8 {
    int* buffer;
    unsigned char count;
    unsigned char capacity;
};
void ResetWordList0209cbb8(struct WordList0209cbb8*);

// USA: func_0209cd24
ARM void FreeWordListBuffer0209cd24(struct WordList0209cbb8* list) {
    if (list->buffer != NULL) {
        func_02012da4(&data_02114e20, list->buffer);
    }
    ResetWordList0209cbb8(list);
}
