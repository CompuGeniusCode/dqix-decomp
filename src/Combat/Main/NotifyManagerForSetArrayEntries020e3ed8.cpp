#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct Struct020e3ed8 {
    char pad[0x14];
    int arr[2];
};

// USA: func_020e3ed8
ARM void NotifyManagerForSetArrayEntries020e3ed8(struct Struct020e3ed8* p) {
    int x = (int)BackgroundLoader::GetInstance();
    int i;
    for (i = 0; i < 2; i++) {
        if (p->arr[i] != -1) {
            ((BackgroundLoader*)(x))->RemoveTask((int)(p->arr[i]));
        }
    }
}
