#include <globaldefs.h>
#include "Grotto/Main/TreasureMapMetadata.h"

int Dispatch020a4244(char*, int);

// USA: func_020117cc
ARM void DispatchAndSetTreasureMapUnknownBit(char* obj, int arg) {
    Dispatch020a4244(obj + 0x63e4, arg);
    ((TreasureMapMetadata*)(obj + 0x6450))->SetInitialByteUnknownBit();
}
