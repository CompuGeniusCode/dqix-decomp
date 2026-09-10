#include <globaldefs.h>

struct Obj5d594;
extern "C" void func_0205d594(struct Obj5d594* obj, unsigned char* outLow, unsigned char* outHigh);

struct ElemTarget0205de24 {
    char pad0[0x4];
    void* matched;
    char pad1[0xE0 - 0x8];
};

struct Struct0205de24 {
    char pad0[0x98];
    unsigned char* field98;
    unsigned char* field9C;
    char pad1[0xb2 - 0xa0];
    unsigned char fieldB2;
    char pad2[0xb4 - 0xb3];
    unsigned char fieldB4;
};

// Picks the background layer whose two nibbles at +0x1c match the key pair and hangs it on the
// window slot the next open will use - field9C[fieldB4], the same slot func_0205e00c hands out for
// an id that is not registered yet. The 0x20-byte records at +0x98 are the ones curated
// ResetBackgroundLayer initialises; func_0204ffc0 reads the nibbles back off the pointer left at
// +0x4 to index data_020f01f8[lo][hi], whose four columns are BG0..BG3 and whose low-nibble-0 row is
// LoadToMainBG0..3CharacterData. Callers pass a high nibble of 1, 2 or 3, almost always with lo 0.
extern "C" ARM void BindBackgroundLayerToNextWindow(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh) {
    if (obj->field98 == 0 || obj->field9C == 0) return;
    struct ElemTarget0205de24* target = (struct ElemTarget0205de24*)(obj->field9C + obj->fieldB4 * 0xE0);
    if (target == 0) return;
    unsigned char* entry;
    unsigned char i = 0;
    unsigned char low, high;
    while (i < obj->fieldB2) {
        entry = obj->field98 + i * 0x20;
        func_0205d594((struct Obj5d594*)entry, &low, &high);
        if (low == keyLow && high == keyHigh) {
            target->matched = entry;
            return;
        }
        i++;
    }
}
