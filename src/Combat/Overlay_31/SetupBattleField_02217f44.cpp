#include <globaldefs.h>
#include "System/Memory.h"

extern "C" void SetField164_02203164(int v);

// USA: func_ov031_02217f44
ARM void SetupBattleField_02217f44(int obj) {
    VectorizedMemset((void*)(obj + 0x138 + 0x1000), 0, 0x64);
    *(int*)(obj + 0x1000 + 0x174) = 0xb68;
    *(int*)(obj + 0x1000 + 0x178) = *(int*)(obj + 0x1000 + 0x9cc);
    *(int*)(obj + 0x1000 + 0x180) = 0x5ea;
    *(int*)(obj + 0x1000 + 0x184) = *(int*)(obj + 0x1000 + 0x9d0);
    SetField164_02203164(obj + 0x138 + 0x1000);
}
