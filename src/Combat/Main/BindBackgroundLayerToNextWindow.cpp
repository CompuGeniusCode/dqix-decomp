#include <globaldefs.h>

struct BackgroundLayer;
extern "C" void func_0205d594(struct BackgroundLayer* layer, unsigned char* outLow, unsigned char* outHigh);

struct TextWindow {
    char unknown0[0x4];
    void* boundLayer;
    char unknown8[0xE0 - 0x8];
};

struct TextWindowManager {
    char unknown0[0x98];
    unsigned char* bgLayers;
    unsigned char* windows;
    char unknowna0[0xb2 - 0xa0];
    unsigned char bgLayerCount;
    char unknownb3[0xb4 - 0xb3];
    unsigned char openWindowCount;
};

// Picks the background layer whose two nibbles at +0x1c match the key pair and hangs it on the
// window slot the next open will use - windows[openWindowCount], the same slot func_0205e00c hands
// out for an id that is not registered yet. The 0x20-byte records at +0x98 are the ones curated
// ResetBackgroundLayer initialises; func_0204ffc0 reads the nibbles back off the pointer left at
// +0x4 to index data_020f01f8[lo][hi], whose four columns are BG0..BG3 and whose low-nibble-0 row is
// LoadToMainBG0..3CharacterData. Callers pass a high nibble of 1, 2 or 3, almost always with lo 0.
// The byte at +0xb2 is how many layer records there are, the same one ClearBgTilemaps loops over,
// and +0xb4 is how many windows are open, the count FindTextWindowById stops its scan at.
extern "C" ARM void BindBackgroundLayerToNextWindow(struct TextWindowManager* manager, unsigned char keyLow, unsigned char keyHigh) {
    if (manager->bgLayers == 0 || manager->windows == 0) return;
    struct TextWindow* target = (struct TextWindow*)(manager->windows + manager->openWindowCount * 0xE0);
    if (target == 0) return;
    unsigned char* entry;
    unsigned char layerIndex = 0;
    unsigned char low, high;
    while (layerIndex < manager->bgLayerCount) {
        entry = manager->bgLayers + layerIndex * 0x20;
        func_0205d594((struct BackgroundLayer*)entry, &low, &high);
        if (low == keyLow && high == keyHigh) {
            target->boundLayer = entry;
            return;
        }
        layerIndex++;
    }
}
