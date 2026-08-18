#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" void func_020938f0(void* obj);

// USA: func_020939ac
ARM void ReleaseHandleField340(void* obj) {
    int token = (int)BackgroundLoader::GetInstance();
    if (*(int*)((char*)obj + 0x340) >= 0) {
        ((BackgroundLoader*)(token))->RemoveTask(*(int*)((char*)obj + 0x340));
        *(int*)((char*)obj + 0x340) = -1;
    }
    func_020938f0(obj);
}
