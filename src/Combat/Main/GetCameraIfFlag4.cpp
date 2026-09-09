#include <globaldefs.h>
extern "C" int func_0202e09c(int);

// Returns the object the game-state root keeps at +0x3b0, but only while bit 0x4 of its first word
// is set. func_0202df68 sets that object up as a camera -- position, target, up vector (0, 0x1000,
// 0), perspective 0x1555 (4:3), near 0x1000 and far 0x190000, and an identity 3x3 at +0x144, which
// func_02076bec copies into the RenderConfig block to billboard an actor. func_ov001_02160768
// swaps the pointer for a 0x268-byte object carrying a name and two combatant references, which
// that reading has to live with. What bit 0x4 gates is not established; func_020100cc reads 0x2.
extern "C" ARM int GetCameraIfFlag4(char* obj) {
    int p = *(int*)(obj + 0x3b0);
    if (p != 0) {
        if (func_0202e09c((int)(p)) & 4) {
            return *(int*)(obj + 0x3b0);
        }
    }
    return 0;
}
