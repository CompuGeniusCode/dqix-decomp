#include <globaldefs.h>

struct SearchStruct0202c1a4 {
    char unknown0[0x1038];
    signed char arr[16];
};

extern "C" extern unsigned short func_0202df58(void);

// Returns the id the multiplayer state holds for the local player. The index is data_021015a0's
// first halfword: func_0202bd68 walks slots 0..3 of this same array and reaches for the record at
// +0x7c0 rather than the +0xbc0 one exactly when the slot equals that halfword, which is the shape
// of "my own entry, not one of the others", and func_0202cddc reads +0x8 of the same block as a
// one-based send-slot override against a sixteen-bit per-station availability mask. The object is
// what GetMultiplayerState (GetMultiplayerState) hands out; its records sit at +0xbc0 + index * 0x74 and
// GetMultiplayerPlayerRecord finds one by searching this array for the id, with the live ones
// flagged in the byte at +0x100c. Nothing decompiled writes the halfword non-zero -- the only two
// writes store 0 -- so in decompiled code this always reads slot 0.
extern "C" ARM signed char GetLocalPlayerId(struct SearchStruct0202c1a4* obj) {
    return obj->arr[func_0202df58()];
}
