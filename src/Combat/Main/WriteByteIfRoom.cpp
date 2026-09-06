#include <globaldefs.h>

#pragma optimize_for_size off

struct ByteWriter020d3084 {
    int remaining;
    unsigned char* ptr;
};

// USA: func_020d3084
ARM void WriteByteIfRoom(struct ByteWriter020d3084* s, int c) {
    if (s->remaining != 0) {
        *s->ptr = c;
        s->remaining--;
    }
    s->ptr++;
}
