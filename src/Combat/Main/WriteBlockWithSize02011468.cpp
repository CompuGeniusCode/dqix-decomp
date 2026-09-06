#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02011468
// Copies 'size' bytes from 'src' into the buffer at +0x5718 and stores the size byte at +0x571c.
ARM void WriteBlockWithSize02011468(void* obj, int size, void* src) {
    memcpy((char*)obj + 0x5718, src, size);
    *((char*)obj + 0x571c) = (char)size;
}
