#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c508(void* p);
extern "C" void func_ov017_021c2380(int a, int b);
unsigned char GetByteField0x252(void* obj);
int CheckSubstructByte0x7cPositive(signed char* obj);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
unsigned char GetField0x397cValue(struct BattleStruct* battleStruct);

// USA: func_ov017_021c25ac  (semantic: ResetField2380ForRange_021c25ac)
extern "C" ARM void func_ov017_021c25ac() {
    struct BattleStruct* bs = GetBattleStruct();
    void* search = func_0202ae18();
    struct CombatantStruct* c = GetCombatantAtField0x397c(bs);
    if (c != 0 && GetByteField0x252(c) != 0 && CheckSubstructByte0x7cPositive((signed char*)c) == 0) {
        for (int i = 0; i < 4; i++) {
            func_ov017_021c2380(i, GetField0x397cValue(bs));
        }
    }
    if (func_0202c508(search) != 0) {
        for (int a = 0; a < 4; a++) {
            for (int b = 0; b < 0x30; b++) {
                func_ov017_021c2380(a, b + 0x70);
            }
        }
    } else {
        for (int i = 0; i < 0x30; i++) {
            func_ov017_021c2380(GetField0x397cValue(bs), i + 0x70);
        }
    }
}
