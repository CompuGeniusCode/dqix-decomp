#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void SetByte0x4(char* obj, unsigned char value);
void SetByte0x7f70(void* obj, unsigned char value);
extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_0216d6a0  (semantic: SetBattleByte8AndNotify_0216d6a0)
extern "C" ARM int func_ov004_0216d6a0(void* obj) {
    struct BattleStruct* battle = GetBattleStruct();
    SetByte0x4((char*)battle, 8);
    SetByte0x7f70(battle, 0);
    func_ov011_021848a0(obj, 0x3e7);
    return 0;
}
