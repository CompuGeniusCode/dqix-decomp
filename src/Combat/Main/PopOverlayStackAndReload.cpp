#include <globaldefs.h>

extern "C" void func_020a1940(int);
extern volatile unsigned char data_02109da4;
extern signed char data_02109dae[];
extern signed char data_020f1962[];

// Pops the overlay-request stack that func_020a1df8 fills - depth in data_02109da4[0], up to eight
// ids in data_02109dae - and, unless the caller passes 0 or the stack has just emptied, re-runs
// func_020a1940 for the id now on top. That is the overlay switch: resource mutex, then
// LoadCompressedOverlay and DecompressAndStaticInitializeOverlay over the OverlayMetadata[35] table
// func_020a1838 builds; it is not decompiled, so what its argument selects is not established.
// The map at data_020f1962 is seven zero bytes here, and 0x020a1f4c is the same for a second stack.
extern "C" ARM void PopOverlayStackAndReload(int flag) {
    if (data_02109da4 == 0) return;
    data_02109da4--;
    if (flag == 0 || data_02109da4 == 0) return;
    signed char i = data_02109dae[data_02109da4 - 1];
    func_020a1940(data_020f1962[i]);
}
