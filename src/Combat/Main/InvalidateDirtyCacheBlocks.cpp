#include <globaldefs.h>
#include "std_library_functions.h"

void CleanInvalidateCacheRange(const void* addr, unsigned int size);

struct HeaderAt0204ab4c {
    char pad0[2];
    unsigned short dirtyMask;
};

struct BufferAt0204ab4c {
    char pad0[8];
    unsigned int totalSize;
    char blocks[0x20 * 16];
};

// USA: func_0204ab4c
ARM void InvalidateDirtyCacheBlocks(struct HeaderAt0204ab4c* header, struct BufferAt0204ab4c* buffer) {
    unsigned int totalSize;
    int flagByte;
    int i;
    memcpy(&totalSize, &buffer->totalSize, 4);
    if (header->dirtyMask == 0xffff) {
        CleanInvalidateCacheRange((const void*)((int)&buffer->blocks[0]), totalSize);
        return;
    }
    flagByte = header->dirtyMask & 0xff;
    for (i = 0; i < 16; i++) {
        if (flagByte & 1) {
            CleanInvalidateCacheRange((const void*)((int)&buffer->blocks[i * 0x20]), 0x20);
        }
        flagByte = (flagByte >> 1) & 0xff;
    }
}
