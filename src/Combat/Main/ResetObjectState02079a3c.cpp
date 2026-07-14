#include <globaldefs.h>
#include "Filesystem/GPC.h"

void ZeroInitGPCPointer(GPCFile** ppGPC);

// USA: func_02079a3c
ARM void* ResetObjectState02079a3c(void* obj) {
    ZeroInitGPCPointer((GPCFile**)(obj));
    ((GPCReadPair*)obj)->ZeroInitializeMachine();
    return obj;
}
