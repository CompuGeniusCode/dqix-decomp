#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Grotto/Main/TreasureMapMetadata.h"

void StoreInvalidTreasureMapMetadata(char* obj);
struct AxisFloats0203b5f8;
extern "C" struct AxisFloats0203b5f8* func_ov017_0218b5b0(void);
extern "C" void func_ov017_0218d77c(int obj, int a);

// USA: func_ov004_02165ad4  (semantic: StoreInvalidTreasureMapAndDispatch_02165ad4)
extern "C" ARM int func_ov004_02165ad4(void) {
    StoreInvalidTreasureMapMetadata((char*)GetBattleStruct());
    func_ov017_0218d77c((int)func_ov017_0218b5b0(), 2);
    return 0;
}
