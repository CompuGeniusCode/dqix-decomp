#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov023_021f6844(void* base, unsigned int id);

// USA: func_ov011_02184604
ARM void DestroyTreeNode_02184604(void* self, unsigned char* node) {
    if (!node) return;
    DestroyTreeNode_02184604(self, *(unsigned char**)(node + 0x18));
    DestroyTreeNode_02184604(self, *(unsigned char**)(node + 0x1c));
    func_ov023_021f6844((unsigned char*)self + 0x118, *(unsigned int*)(node + 0x0));
    ((SafeAllocator*)(node + 0x4))->Destroy();
}
