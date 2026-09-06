#include <globaldefs.h>

struct Element0209ccc8 {
    int value;
};

struct ElementList0209ccc8 {
    struct Element0209ccc8* buffer;
    unsigned char count;
    unsigned char capacity;
};

// USA: func_0209ccc8
ARM void AppendElementCapped0209ccc8(struct ElementList0209ccc8* list, struct Element0209ccc8* value) {
    unsigned char count = list->count;
    if (count < (unsigned int)list->capacity) {
        list->count = count + 1;
        list->buffer[count] = *value;
    }
}
