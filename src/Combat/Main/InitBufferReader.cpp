#include <globaldefs.h>

struct StreamHeader {
    int field0;
    int size;
};

struct StreamState {
    char pad[0xC];
    struct StreamHeader* buffer;
    int length;
    struct StreamHeader* cursor;
    void* dataStart;
    void* dataEnd;
    int field20;
};

// USA: func_02030734
ARM int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length) {
    s->buffer = buffer;
    s->length = length;
    s->cursor = s->buffer;
    s->dataStart = (char*)s->buffer + 0x10;
    s->dataEnd = (char*)s->buffer + s->cursor->size;
    s->field20 = 0;
    return 1;
}
