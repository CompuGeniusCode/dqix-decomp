#include <globaldefs.h>
#include "Grotto/Main/GrottoStruct.h"

// USA: func_020117cc
ARM void DispatchAndSetTreasureMapUnknownBit(char* obj, int arg) {
    ((GrottoStruct*)(obj + 0x63e4))->LoadActiveMetadataFromDetailed((DetailedTreasureMapData*)arg);
    ((TreasureMapMetadata*)(obj + 0x6450))->SetInitialByteUnknownBit();
}
