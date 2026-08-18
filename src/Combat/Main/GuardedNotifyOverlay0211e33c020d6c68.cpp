#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" void func_020a1940(int);
extern "C" void _Z28PopulateOv33BackgroundLoaderPvji(void*, int, int);
extern int data_0211e33c;

// USA: func_020d6c68
ARM void GuardedNotifyOverlay0211e33c020d6c68(void) {
    if ((int)BackgroundLoader::GetInstance() != 0) return;
    asm {
        ldr r0, =0x22
        bl func_020a1940
        ldr r0, =data_0211e33c
        mov r1, #0x30000
        mov r2, #0x14
        bl _Z28PopulateOv33BackgroundLoaderPvji
    }
}
