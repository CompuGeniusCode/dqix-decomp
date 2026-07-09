#include <globaldefs.h>

struct Reloc020b01e0 { char pad[0x14]; unsigned int offset; };

// USA: func_020b01e0
ARM void RelocateOffsetAt0x14(struct Reloc020b01e0* p) {
    p->offset = p->offset + (unsigned int)p;
}
