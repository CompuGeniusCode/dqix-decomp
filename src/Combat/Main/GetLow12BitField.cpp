#include <globaldefs.h>

struct Bits020a93d0 { unsigned int count : 12; };

// USA: func_020a93d0
ARM unsigned int GetLow12BitField(struct Bits020a93d0* p) {
    return p->count;
}
