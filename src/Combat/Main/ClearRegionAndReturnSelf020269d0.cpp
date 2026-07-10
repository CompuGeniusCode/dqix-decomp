#include <globaldefs.h>

void ClearRegion0207bcc4(char* obj);

// USA: func_020269d0
ARM char* ClearRegionAndReturnSelf020269d0(char* obj) {
    ClearRegion0207bcc4(obj);
    return obj;
}
