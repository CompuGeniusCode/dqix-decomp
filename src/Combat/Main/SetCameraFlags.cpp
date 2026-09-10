#include <globaldefs.h>

// Sets bits in the flag byte at +0x244 of the camera. The one decompiled call site, func_02053634,
// passes the result of GetCameraIfFlag4 at 0x020100f8, and 18 of the 19 callers also reference that
// function, which returns BattleStruct+0x3b0 -- the same field the curated GetActiveCamera reads.
// The neighbours at 0x020a2800, 0x020a2830 and 0x020a2868 configure that object's vector at +0x220
// and its view angle; 0x020a28b0 clears this byte and 0x020a28c4 / 0x020a28d0 set and clear the word
// at +0x240. The masks passed are 1, 2, 3 and 0x10; what the individual bits do is not established.
extern "C" ARM void SetCameraFlags(unsigned char* obj, unsigned char mask) {
    obj[0x244] |= mask;
}
