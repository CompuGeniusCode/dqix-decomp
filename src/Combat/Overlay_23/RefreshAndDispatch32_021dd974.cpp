#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void func_ov023_021dfb4c(void* obj);
extern "C" void func_ov023_021ddae4(void* obj);
extern "C" void func_ov023_021dc520(void* obj);
extern "C" void func_ov023_021dd404(void* obj);
int GetWord0x0(int* obj);
int DispatchByMode77c_021ddbb8(void* obj, int a, int b);

// USA: func_ov023_021dd974
ARM void RefreshAndDispatch32_021dd974(void* obj) {
    if (!(*(unsigned short*)((char*)obj + 0x774) & 0x4000)) {
        func_ov023_021dfb4c(obj);
    }
    func_ov023_021ddae4(obj);

    if (*(signed char*)((char*)obj + 0x77d) >= 0) {
        func_ov023_021dc520(obj);
        func_ov023_021dd404(obj);
    }

    if (!(*(unsigned short*)((char*)obj + 0x774) & 0x40)) return;

    GetWord0x0((int*)GetBattleStruct());

    if (!(*(unsigned short*)((char*)obj + 0x774) & 0x20)) return;

    DispatchByMode77c_021ddbb8(obj, 0, 8);
    *(unsigned short*)((char*)obj + 0x774) &= ~0x20;
}
