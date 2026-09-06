#include <globaldefs.h>
#include "System/Memory.h"

struct Stream0200fd14 { char* ptr; };

// USA: func_0200fd14
// Copies 'length' bytes out of the stream at stream->ptr and advances the pointer.
ARM void ReadStreamBlock0200fd14(struct Stream0200fd14* stream, void* dst, unsigned int length) {
    VectorizedInvertedMemcpy(stream->ptr, dst, length);
    stream->ptr += length;
}
