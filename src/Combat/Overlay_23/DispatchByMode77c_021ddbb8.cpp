#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetWord0x0(int* obj);
extern "C" int func_0203b19c(int, int, int);
extern "C" int func_0203b110(int, int, int);

// USA: func_ov023_021ddbb8
ARM int DispatchByMode77c_021ddbb8(void* obj, int a, int b) {
    int w = GetWord0x0((int*)GetBattleStruct());
    signed char sb = *(signed char*)((char*)obj + 0x77c);
    if (sb == 1) {
        return func_0203b19c(w, a, b);
    }
    return func_0203b110(w, a, b);
}
