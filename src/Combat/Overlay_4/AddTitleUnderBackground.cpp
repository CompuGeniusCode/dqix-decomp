#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "Combat/Main/BattleList.h"

extern "C" void* func_ov011_021845f8(void* a, int b);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void func_ov023_021f745c(void* buf, void* obj, int msgId, int p3, int p4, void* fmt, int p6, int p7, int p8);

struct ListHead_021f67ac;
struct ListNode_021f67ac;
extern "C" void func_ov023_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

extern char strMenuBgTitleUnderPac;
extern char strMenuBgTitleUnder1Pac;
extern char strMenuBgTitleUnder2Pac;
extern char data_ov023_021fe4f0;

struct MenuBackgroundNode { void* vtable; char unknown4[0x54 - 4]; };

// Builds the node that draws the bg_title_under background and appends it to the owner's node
// list. The file is menu/bg_title_under.pac, bg_title_under1.pac or bg_title_under2.pac, all
// three of which exist in data/menu, chosen by the byte at BattleStruct+0x7f71.
// func_ov011_021848a8 steps that byte through 0, 1, 2 once an accumulator passes 0xe10, but the
// accumulator grows by BattleStruct+0x3c4 per call - a frame scale whose unit is not
// established - so the real period is unknown.
// The first word of the 0x54-byte node is stamped with data_ov023_021fe4f0, four consecutive
// relocated function pointers, before func_ov023_021f745c fills the rest in; 0x67 is the id it
// is given. Reading "title_under" as the title screen's lower screen is a guess from the name
// alone; the upper-screen counterpart is AddTitleUpperBackground, the next entry in the same table.
extern "C" ARM int AddTitleUnderBackground(void* obj) {
    void* fmt = 0;
    unsigned char titleBgVariant = *((unsigned char*)GetBattleStruct() + 0x7f71);
    switch (titleBgVariant) {
        case 0: fmt = &strMenuBgTitleUnderPac; break;
        case 1: fmt = &strMenuBgTitleUnder1Pac; break;
        case 2: fmt = &strMenuBgTitleUnder2Pac; break;
    }

    void* buf = func_ov011_021845f8(obj, 3);
    if (!buf) {
        return 0;
    }
    ((SafeAllocator*)((char*)buf + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)buf + 4))->Allocate(0x54);
    if (!block) {
        return 0;
    }

    struct MenuBackgroundNode nodeTemplate;
    nodeTemplate.vtable = &data_ov023_021fe4f0;
    memcpy(block, &nodeTemplate, sizeof(MenuBackgroundNode));

    func_ov023_021f745c(block, obj, 0x67, 3, 0, fmt, 0, 3, 2);

    func_ov023_021f67ac((struct ListHead_021f67ac*)func_ov011_021849c8(obj), (struct ListNode_021f67ac*)block);
    return 0;
}
