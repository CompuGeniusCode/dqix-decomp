#include <globaldefs.h>

struct WordList0209cbb8 {
    int* buffer;
    unsigned char count;
    unsigned char capacity;
};

// USA: func_0209cbb8
ARM void ResetWordList0209cbb8(struct WordList0209cbb8* list) {
    list->buffer = NULL;
    list->count = 0;
    list->capacity = 0;
}
