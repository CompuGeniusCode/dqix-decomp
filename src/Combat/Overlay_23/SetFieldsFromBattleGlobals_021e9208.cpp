#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetField5cb0Value(char* obj);
int GetField5cb4Value(char* obj);
extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov023_021e9208
ARM int SetFieldsFromBattleGlobals_021e9208(void* obj) {
    char* bs = (char*)GetBattleStruct();
    func_ov017_021d6134(obj, GetField5cb0Value(bs));
    func_ov017_021d6134((char*)obj + 0x8, GetField5cb4Value(bs));
    return 1;
}
