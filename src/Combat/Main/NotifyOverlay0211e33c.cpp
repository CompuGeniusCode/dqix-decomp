#include <globaldefs.h>

extern "C" void func_020a1940(int);
extern "C" void func_ov033_022a2180(void*, int, int);

extern int data_0211e33c;

// USA: func_020d6c0c
ARM void NotifyOverlay0211e33c(void) {
    asm {
        ldr r0, =0x22
        bl func_020a1940
        ldr r0, =data_0211e33c
        mov r1, #0x30000
        mov r2, #0x14
        bl func_ov033_022a2180
    }
}
