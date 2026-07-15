#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern "C" void func_02000b9c(unsigned int);

// USA: func_ov031_0220aa68
ARM void SetActiveContextByte9_0220aa68(unsigned char v) {
    func_02000b9c(0x2000c44);
    void* mgr = *(void**)((char*)data_02111304.activeContext + 0xa4);
    if (mgr) {
        *(unsigned char*)((char*)mgr + 9) = v;
    }
}
