// USA: func_ov003_0216d818
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

int GetGlobalField0x1c020421a0();
void ReinitController02043204(char* obj);

struct Entry_0205d6a0;
void ResetEntryList0205d6a0(struct Entry_0205d6a0* a, int flag);

extern "C" void func_ov003_0216d77c(void* obj);

ARM void ResetGlobalsAndReinit_0216d818(char* obj) {
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    ReinitController02043204((char*)GetGlobalField0x1c020421a0());
    ResetEntryList0205d6a0(*(struct Entry_0205d6a0**)(obj + 0x1000 + 0x2c0), 0);
    func_ov003_0216d77c(obj);
}
