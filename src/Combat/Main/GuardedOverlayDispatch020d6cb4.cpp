#include <globaldefs.h>

extern "C" void func_020a1940(int);
extern "C" void func_020a1bb4(int);
extern "C" int func_ov023_021d8a40(void*, int*);
extern "C" void func_ov017_0218b688(int);
extern "C" void func_ov024_021d92f0(int, void*, int*);
extern int data_02114e20;

// USA: func_020d6cb4
ARM void GuardedOverlayDispatch020d6cb4(void) {
    asm {
        ldr r5, =0x1e
        mov r1, #0
        mov r0, r5
        str r1, [sp, #0]
        bl func_020a1940
        ldr r0, =data_02114e20
        add r1, sp, #0
        bl func_ov023_021d8a40
        mov r4, r0
        mov r0, r5
        bl func_020a1bb4
        mov r0, r4
        bl func_ov017_0218b688
        mov r0, r5
        bl func_020a1940
        ldr r1, =data_02114e20
        mov r0, r4
        add r2, sp, #0
        bl func_ov024_021d92f0
        mov r0, r5
        bl func_020a1bb4
    }
}
