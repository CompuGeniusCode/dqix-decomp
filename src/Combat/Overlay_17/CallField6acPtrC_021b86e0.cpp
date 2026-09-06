#include <globaldefs.h>

void SetCombatWorkFlags0x2And0x4(void* work);

// USA: func_ov017_021b86e0
ARM void CallField6acPtrC_021b86e0(void* obj) {
    void* p = *(void**)((char*)obj + 0x6ac);
    if (p) SetCombatWorkFlags0x2And0x4(p);
}
