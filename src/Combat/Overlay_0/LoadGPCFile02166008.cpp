#include <globaldefs.h>
#include "Filesystem/GPC.h"

void ShiftInBitOnGlobalObject(void);
void CallFunc02030110OnGlobalObject(void);

extern char data_ov000_02183a2f[];
extern char data_0211e33c[];

// USA: func_ov000_02166008
ARM unsigned int LoadGPCFile02166008(void* unused, GPCReadPair* readPair, int flag) {
    unsigned int length;
    if (flag) {
        ShiftInBitOnGlobalObject();
        CallFunc02030110OnGlobalObject();
    }
    readPair->ZeroInitialize();
    LoadAndDecompressGPCHeaderAndInnerFileInfo(&readPair->pGPCFile, readPair->machine,
        data_ov000_02183a2f, data_0211e33c, length, 0x30000, false, NULL);
    return length;
}
