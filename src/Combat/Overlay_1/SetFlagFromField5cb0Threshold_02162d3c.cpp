#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetField5cb0Value(char* obj);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov001_02162d3c  (semantic: SetFlagFromField5cb0Threshold_02162d3c)
extern "C" ARM int func_ov001_02162d3c(void* obj) {
    int v = GetField5cb0Value((char*)GetBattleStruct());
    func_ov017_021d6134(obj, v >= 0x13 ? 1 : 0);
    return 1;
}
