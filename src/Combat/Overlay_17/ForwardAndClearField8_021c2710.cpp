#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"

extern AllocatorUnion data_02114e20;
void TailForward02012da4(AllocatorUnion* alloc, void* data);

// USA: func_ov017_021c2710
ARM void ForwardAndClearField8_021c2710(unsigned char* self) {
    void* p = *(void**)(self + 8);
    if (p != NULL) {
        TailForward02012da4(&data_02114e20, p);
        *(void**)(self + 8) = NULL;
    }
    self[1] = 1;
}
