#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct Struct0216fd38 {
    volatile int field0;
    unsigned char pad[0xa0 - 0x4];
    unsigned char flagA0;
};

// USA: func_ov000_0216fd38
ARM int CheckOrSetFlagA0_0216fd38(struct Struct0216fd38* obj) {
    if (obj->flagA0) return 1;
    if (obj->field0 < 0) return 0;
    if (((BackgroundLoader*)((int)BackgroundLoader::GetInstance()))->GetTaskStatus((int)(obj->field0)) == 0) {
        return 0;
    }
    obj->flagA0 = 1;
    return 1;
}
