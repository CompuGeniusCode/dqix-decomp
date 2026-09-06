#include <globaldefs.h>

extern int data_ov004_021707d8;
void* ResetCombatantFields_0215a2f8(void* obj);
extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_0215b330  (semantic: ResetSomeCombatant_0215b330)
extern "C" ARM void* func_ov004_0215b330(void* obj) {
    ResetCombatantFields_0215a2f8(*(void**)((char*)&data_ov004_021707d8 + 8));
    func_ov011_021848a0(obj, 0x39e);
    return 0;
}
