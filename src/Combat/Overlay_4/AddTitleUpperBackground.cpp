#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "Combat/Main/BattleList.h"

extern "C" void* func_ov011_021845f8(void* a, int b);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void func_ov023_021f745c(void* buf, void* obj, int msgId, int p3, void* p4, void* fmt, int p6, int p7, int p8);

struct ListHead_021f67ac;
struct ListNode_021f67ac;
extern "C" void func_ov023_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

extern char strMenuBgUpGp2;
extern char strBgUpLgPac;
extern char strMenuBgUp1Gp2;
extern char strBgUp1LgPac;
extern char strMenuBgUp2Gp2;
extern char strBgUp2LgPac;
extern char data_ov023_021fe4f0;

struct MenuBackgroundNode { void* vtable; char unknown4[0x54 - 4]; };

// The counterpart of AddTitleUnderBackground, the neighbouring entry in the ov004 pointer table at
// 0x02170224 and 0x02170228: same 0x54-byte node, same variant byte at BattleStruct+0x7f71, but
// the file is named inside an archive - menu/bg_up.gp2, bg_up1.gp2 or bg_up2.gp2, from which
// the member "bg_up<n>_<LG>.pac" is taken. <LG> is a placeholder the loader fills in with the
// language code; bg_up.gp2's name table carries de, en, es, fr and it.
// bg_up.gp2 also holds title_upper.bncg, which is what ties this pair to the title screen and
// this half of it to the upper screen.
// The id passed to func_ov023_021f745c is 0x69 here rather than 0x67.
extern "C" ARM int AddTitleUpperBackground(void* obj) {
    void* fmt = 0;
    void* p4 = 0;
    unsigned char titleBgVariant = *((unsigned char*)GetBattleStruct() + 0x7f71);
    switch (titleBgVariant) {
        case 0: p4 = &strMenuBgUpGp2; fmt = &strBgUpLgPac; break;
        case 1: p4 = &strMenuBgUp1Gp2; fmt = &strBgUp1LgPac; break;
        case 2: p4 = &strMenuBgUp2Gp2; fmt = &strBgUp2LgPac; break;
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

    func_ov023_021f745c(block, obj, 0x69, 3, p4, fmt, 1, 2, 0);

    func_ov023_021f67ac((struct ListHead_021f67ac*)func_ov011_021849c8(obj), (struct ListNode_021f67ac*)block);
    return 0;
}
