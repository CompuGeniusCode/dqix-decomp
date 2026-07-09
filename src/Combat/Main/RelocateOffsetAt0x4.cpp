#include <globaldefs.h>

struct Reloc020b0268 { char pad[0x4]; unsigned int offset; };

// USA: func_020b0268
ARM void RelocateOffsetAt0x4(struct Reloc020b0268* p) {
    p->offset = p->offset + (unsigned int)p;
}
