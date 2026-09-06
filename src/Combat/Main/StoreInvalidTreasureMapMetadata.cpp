#include <globaldefs.h>
#include "System/Memory.h"
#include "Grotto/Main/TreasureMapMetadata.h"

// USA: func_02011a40
ARM void StoreInvalidTreasureMapMetadata(char* obj) {
    TreasureMapMetadata local;
    local.SetMapType(TreasureMapType_Invalid);
    VectorizedInvertedMemcpy(&local, obj + 0x6482, 0x1c);
}
