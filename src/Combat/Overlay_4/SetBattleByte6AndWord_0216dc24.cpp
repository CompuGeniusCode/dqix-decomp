#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void SetByte0x4(char* obj, unsigned char value);
void SetWord0x7f6c(void* obj, int value);
extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_0216dc24  (semantic: SetBattleByte6AndWord_0216dc24)
extern "C" ARM int func_ov004_0216dc24(void* obj) {
    struct BattleStruct* battle = GetBattleStruct();
    SetByte0x4((char*)battle, 6);
    SetWord0x7f6c(battle, 2);
    func_ov011_021848a0(obj, 0x3e7);
    return 0;
}
