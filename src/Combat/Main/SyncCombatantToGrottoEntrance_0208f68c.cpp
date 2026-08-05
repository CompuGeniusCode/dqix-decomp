#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Grotto/Main/GrottoStruct.h"

extern "C" void* func_02012fe4(void* unused);
void CopyVec3(int* dst, int* src);
void StoreVec3AsShortsAt0x5c(unsigned char* dst, int* src);
void ClearFlag0x1InField0x6c(unsigned char* obj);
extern "C" int func_020370a0(void* obj, int id, int flags);

extern int data_020e8d3c;

struct Vec3Local_0208f68c { int x, y, z; };

// USA: func_0208f68c  (semantic: SyncCombatantToGrottoEntrance_0208f68c)
extern "C" ARM void func_0208f68c(unsigned char* obj) {
    if (obj[0xb4] != 0) {
        BattleStruct* battle = GetBattleStruct();
        void* p = func_02012fe4(battle);
        unsigned short val = *(unsigned short*)p;
        GrottoStruct* grotto = GetGrottoStruct(battle);
        Vec3Local_0208f68c constVec = *(Vec3Local_0208f68c*)&data_020e8d3c;
        Vec3Local_0208f68c grottoVec = *(Vec3Local_0208f68c*)((char*)grotto + 0x10);
        int zoneId = *(int*)((char*)grotto + 0xc);
        if (zoneId != 0 && *(unsigned char*)grotto != 0) {
            if (zoneId == val) {
                CopyVec3((int*)(obj + 0x4c), (int*)&grottoVec);
                StoreVec3AsShortsAt0x5c(obj + 8, (int*)&constVec);
                func_020370a0(obj + 8, 0, 0);
                ClearFlag0x1InField0x6c(obj + 8);
                obj[0xb6] = 1;
            }
            obj[0xb5] = 0;
        }
    }
}
