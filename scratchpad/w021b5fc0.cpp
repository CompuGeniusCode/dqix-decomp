#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int func_ov017_0218b5b0(void);
int HasNonZeroByteAtOfField498_0218d75c_0218d75c(void* obj);
unsigned int GetBattleScaleCount(struct BattleStruct* battleStruct);
int GetGlobal02109400(void);
extern "C" void func_02094ab0(int a);
extern "C" void func_ov017_021b5a30(void* obj);
int GetGlobalField0x1c020421a0();
void SetByteField0x253(void* obj);
extern "C" void func_ov017_021b6090(void* self);

// USA: func_ov017_021b5fc0
ARM int CheckAndFinalizeBattleScale_021b5fc0(unsigned char* self) {
    struct BattleStruct* battle = GetBattleStruct();
    int scaleCount = GetBattleScaleCount(battle);
    func_ov017_0218b5b0();

    if (self[0x54] != 0) {
        if (HasNonZeroByteAtOfField498_0218d75c_0218d75c((void*)func_ov017_0218b5b0()) != 0) {
            return 5;
        }
        self[0x16] = 0;
        func_02094ab0(GetGlobal02109400());
        func_ov017_021b5a30((void*)self);
        self[1] = 1;
        *(int*)((char*)GetGlobalField0x1c020421a0() + 0x2d8) = 0;
        return 6;
    } else {
        func_ov017_021b6090((void*)self);
        void* g = (void*)GetGlobalField0x1c020421a0();
        unsigned char field16 = self[0x16];
        if (scaleCount < field16) {
            self[0x16] = field16 - scaleCount;
            goto return5;
        }
        self[0x16] = 0;
        func_02094ab0(GetGlobal02109400());
        SetByteField0x253((void*)*(int*)(self + 0x1c));
        func_ov017_021b5a30((void*)self);
        self[1] = 1;
        *(int*)((char*)g + 0x2d8) = 0;
        return 6;
    }
return5:
    return 5;
}
