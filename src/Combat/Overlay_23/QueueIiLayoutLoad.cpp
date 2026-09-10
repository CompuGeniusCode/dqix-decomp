#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct ItemRecordTable;
struct ItemRecord {
    char unknown0[8];
    unsigned int nibble : 4;
    unsigned int restBits : 28;
};
extern "C" ItemRecord* FindItemRecordById(struct ItemRecordTable*, int);

extern "C" void func_ov023_021e20c0(void*);

extern int strDataAniLayIieLia;
extern int strDataAniLayIiuLia;

struct SubMenuScreen {
    char unknown0[0x48];
    ItemRecordTable* itemTable;
    ItemRecord* itemRecord;
    char unknown50[0x73c - 0x50];
    int layoutTaskId;
    char unknown740[0x770 - 0x740];
    short selectedItemId;
    char unknown772[0x79a - 0x772];
    signed char loadedLayoutVariant;
};

// Queues the BackgroundLoader read of the layout matching the record for the current selection at
// +0x770: data/ani/lay_iie.lia when bit 3 of the record byte at +0x8 is clear, lay_iiu.lia when
// it is set. That byte is the low nibble of the word at +0x8 of one 0x20-byte item record out of
// itemdt_<LG>.nat, the table FindItemRecordById searches by the id halfword at +0x18. The object at
// +0xcc that the layout builds is cleared first, and it returns 6. It only reads the answer cached
// at +0x79a - func_ov023_021e04e8, the poll step, writes it - so the two together fire the load only
// when the choice flips. "ii" is the prefix shared by several ov023 assets (oiij, oiir, bg_iidc,
// bg_iilist, str_ii); its expansion, and so the e/u split, is not established.
extern "C" ARM int QueueIiLayoutLoad(struct SubMenuScreen* screen) {
    int loader = (int)BackgroundLoader::GetInstance();
    if (screen->itemTable != NULL) {
        screen->itemRecord = FindItemRecordById(screen->itemTable, screen->selectedItemId);
    }
    ItemRecord* record = screen->itemRecord;
    if (record != NULL) {
        unsigned int nibble = record->nibble;
        int wantsEVariant = (nibble <= 7);
        signed char wantedVariant = (wantsEVariant != 0);
        signed char loadedVariant = screen->loadedLayoutVariant;
        if (loadedVariant != wantedVariant) {
            func_ov023_021e20c0((char*)screen + 0xcc);
            record = screen->itemRecord;
            unsigned int nibble2 = record->nibble;
            int wantsEVariantRecheck = (nibble2 <= 7);
            if (wantsEVariantRecheck) {
                screen->layoutTaskId = ((BackgroundLoader*)(loader))->QueueLoadFile((const char*)((int)&strDataAniLayIieLia), (SafeAllocator*)(0));
            } else {
                screen->layoutTaskId = ((BackgroundLoader*)(loader))->QueueLoadFile((const char*)((int)&strDataAniLayIiuLia), (SafeAllocator*)(0));
            }
        }
    }
    return 6;
}
