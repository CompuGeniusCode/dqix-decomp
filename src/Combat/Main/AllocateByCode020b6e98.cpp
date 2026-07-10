#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"

struct FormatInfo020b2a6c;
int GetAlignedSizeByCode020b2a6c(unsigned char* code, struct FormatInfo020b2a6c* info);

// USA: func_020b6e98
ARM void* AllocateByCode020b6e98(AllocatorUnion* alloc, unsigned char* code, struct FormatInfo020b2a6c* info) {
    return alloc->Allocate(GetAlignedSizeByCode020b2a6c(code, info));
}
