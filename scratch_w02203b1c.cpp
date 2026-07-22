#include <globaldefs.h>
#include "System/ProcessorContext.h"

ARM int GetRemainingOrStatus_0220a800(char* self);

// USA: func_ov031_02203b1c
#pragma optimize_for_size off
ARM int func_ov031_02203b1c(void) {
    char* mgr = *(char**)((char*)data_02111304.activeContext + 0xa4);
    int v44;
    if (mgr != NULL) {
        if (*(unsigned char*)(mgr + 9) != 0) {
            return GetRemainingOrStatus_0220a800(mgr);
        }
        v44 = *(int*)(mgr + 0x44);
        if (v44 != 0) goto ret_v44;
        {
            unsigned char b8 = *(unsigned char*)(mgr + 8);
            if (b8 != 4) {
                if ((unsigned char)(b8 + 0xf6) > 1) {
                    goto ret_neg1;
                }
            }
        }
    ret_v44:
        return v44;
    ret_neg1:
        return -1;
    }
    return 0;
}
