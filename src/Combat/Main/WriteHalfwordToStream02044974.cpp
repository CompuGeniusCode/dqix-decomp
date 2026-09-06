#include <globaldefs.h>

struct ByteStream02044974 {
    unsigned char* cursor;
};

// USA: func_02044974
ARM void WriteHalfwordToStream02044974(struct ByteStream02044974* stream, int value) {
    unsigned short v = value;
    unsigned char* p = stream->cursor;
    stream->cursor = p + 1;
    *p = v;
    p = stream->cursor;
    stream->cursor = p + 1;
    *p = v >> 8;
}
