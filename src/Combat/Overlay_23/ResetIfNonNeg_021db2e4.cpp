#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


// USA: func_ov023_021db2e4
ARM void ResetIfNonNeg_021db2e4(volatile int* p) {
    if (!p) return;
    if (*p < 0) return;
    ((BackgroundLoader*)((int)BackgroundLoader::GetInstance()))->RemoveTask((int)(*p));
    *p = -1;
}
