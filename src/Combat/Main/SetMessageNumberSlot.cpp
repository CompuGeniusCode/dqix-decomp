#include <globaldefs.h>

struct StoreStruct {
    char pad[0x8b0];
    int arr[0x10];
};

// Writes slot `index` of the int array at +0x8b0 of the message work object -- presumably the
// number substituted into that message parameter, though no reader of the array is decompiled.
// The object has sixteen parallel slots: a 0x40-byte name buffer at +0x4ac (SetMessageNameSlot),
// this array, and two per-slot byte arrays at +0x8f1 and +0x902 written by func_020465d8 and
// SetMessageNumberDigits; ResetMessageBuilder clears all four together. The usual shape is GetMessageWork,
// ResetMessageBuilder, fill slots, FormatMessageText -- see func_ov003_0216d8d4.
extern "C" ARM void SetMessageNumberSlot(struct StoreStruct* base, int index, int value) {
    if (index < 0) {
        return;
    }
    if (index < 0x10) {
        base->arr[index] = value;
    }
}
