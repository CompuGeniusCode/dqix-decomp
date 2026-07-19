#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);
extern "C" int func_0202c540(void* p);
void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021cfabc  (semantic: EnqueueEventTag161_021cfabc)
extern "C" ARM void func_ov017_021cfabc(void) {
    void* x = func_0202ae18();
    if (CheckField0NonZero((int*)x) != 0 && func_0202c540(x) == 0) {
        GetBattleStruct();
        void* p = GetData02100044();
        unsigned char buf[0x14];
        buf[0] = 0xa1;
        func_0205e330(p, buf, 0);
    }
}
