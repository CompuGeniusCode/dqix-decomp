#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Grotto/Main/GrottoStruct.h"

extern "C" int func_0201b588(int id);
extern unsigned short data_020fb3f0;

// USA: func_0201bfd4
ARM void MaybeClearGrottoState0201bfd4(void) {
    GrottoStruct* grotto = GetGrottoStruct(GetBattleStruct());
    if (func_0201b588(data_020fb3f0) != 0) return;
    if (grotto->unknown1[4] != 0) {
        grotto->unknown1[3] = 0;
        grotto->unknown1[4] = 0;
    }
}
