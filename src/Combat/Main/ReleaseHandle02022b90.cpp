#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


// USA: func_02022b90
ARM void ReleaseHandle02022b90(void* owner, int* handle) {
    ((BackgroundLoader*)((int)BackgroundLoader::GetInstance()))->RemoveTask((int)(*handle));
    *handle = -1;
}
