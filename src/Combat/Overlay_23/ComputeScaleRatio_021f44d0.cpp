#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov023_021f44d0  (semantic: ComputeScaleRatio_021f44d0)
extern "C" ARM int func_ov023_021f44d0(void* obj) {
    GetBattleStruct();
    unsigned int a = *(unsigned int*)((char*)obj + 0x5000 + 0x8c4);
    unsigned short b = *(unsigned short*)((char*)obj + 0x5800 + 0xcc);
    unsigned short c = *(unsigned short*)((char*)obj + 0x5800 + 0xce);
    float fa = (float)a;
    float fb = (float)b;
    float fc = (float)c;
    float result = fa * (fc / fb);
    if (0.0f < result) {
        if (result < 1.0f) {
            result = 1.0f;
        }
    }
    return (int)result;
}
