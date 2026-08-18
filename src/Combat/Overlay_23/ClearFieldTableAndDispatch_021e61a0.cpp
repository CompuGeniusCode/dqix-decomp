#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


// USA: func_ov023_021e61a0  (semantic: ClearFieldTableAndDispatch_021e61a0)
extern "C" ARM void func_ov023_021e61a0(void* obj) {
    int listPtr = (int)BackgroundLoader::GetInstance();
    for (int i = 0; i < 0xc; i++) {
        if (*(short*)((char*)obj + (i << 1) + 0xb00 + 0xf4) > -1) {
            ((BackgroundLoader*)(listPtr))->RemoveTask((int)(*(short*)((char*)obj + (i << 1) + 0xb00 + 0xf4)));
        }
        *(short*)((char*)obj + (unsigned int)(i << 1) + 0xb00 + 0xf4) = -1;
    }
}
