#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern int data_ov000_02184220;

// USA: func_ov000_02160de4
ARM void HandleField_02160de4(void* obj) {
    int dataVal = (int)BackgroundLoader::GetInstance();
    if (((BackgroundLoader*)(dataVal))->GetTaskStatus((int)(*(short*)((char*)obj + 0x7700 + 0x30))) >= 0) {
        return;
    }
    ((BackgroundLoader*)(dataVal))->RemoveTask((int)(*(short*)((char*)obj + 0x7700 + 0x30)));
    *(short*)((char*)obj + 0x7700 + 0x30) = -1;
    *(int*)((char*)obj + 0xea8) = 0x11;
    *(int*)((char*)obj + 0xeac) = 0;
    data_ov000_02184220 = 1;
}
