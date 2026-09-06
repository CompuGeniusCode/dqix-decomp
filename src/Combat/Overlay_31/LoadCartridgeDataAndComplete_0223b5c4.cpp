#include <globaldefs.h>
#include "Filesystem/CardReadManager.h"
#include "Filesystem/LowNitroHandle.h"

void TailCallOnTaskCompletion_0223b604(NitroHandle* handle);

// USA: func_ov031_0223b5c4
ARM int LoadCartridgeDataAndComplete_0223b5c4(NitroHandle* a, void* b, unsigned int c, unsigned int d) {
    LoadDataFromCartridgeToMemory((unsigned int)-1, c + *(unsigned int*)((char*)a + 0x28), b, d,
        TailCallOnTaskCompletion_0223b604, a, 1);
    return 6;
}
