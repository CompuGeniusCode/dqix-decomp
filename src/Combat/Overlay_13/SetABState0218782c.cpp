#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


// USA: func_ov013_0218782c  (semantic: SetABState0218782c)
extern "C" ARM void func_ov013_0218782c(void* obj, int a, int b) {
    char* o = (char*)obj;
    if (o[0x67] == a && (unsigned char)o[0x68] == (unsigned int)b) return;

    int valid = (a >= 0 && a <= 3);
    if (!valid) return;
    if ((unsigned int)b >= 5) return;

    o[0x67] = (char)a;
    o[0x68] = (char)b;

    if (*(int*)(o + 0x5c) >= 0) {
        int p = (int)BackgroundLoader::GetInstance();
        ((BackgroundLoader*)(p))->RemoveTask((int)(*(int*)(o + 0x5c)));
        *(int*)(o + 0x5c) = -1;
    }

    ((unsigned char*)o)[0x69] |= 1;
    o[0x66] = 0;
}
