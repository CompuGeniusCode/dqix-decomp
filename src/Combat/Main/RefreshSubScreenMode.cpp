#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Grotto/Main/GrottoStruct.h"

extern "C" {
    void* GetMultiplayerState(GrottoStruct* grotto);
    int IsHostOrSinglePlayer(void* something);
    void* GetZoneState(void);
    int func_ov017_0218b5b0(void);
}

struct GlobalStateFlags;
struct GameMainNodeList;
struct NaviManager;

struct ZoneModeFlags {
    char unknown0[0xc];
    unsigned char zoneMode : 4;
    unsigned char nibbleHi : 4;
};

extern "C" void func_020dc214(int mode);
extern "C" int* GetNaviManager(void);
extern "C" void func_020941b0(struct NaviManager* naviManager);
extern "C" void* GetGlobalStateFlags(void);
extern "C" void ClearGlobalStateFlags(struct GlobalStateFlags* word, unsigned int mask);
extern "C" int func_02046b60(struct GameMainNodeList* list, int id);

// Recomputes what the bottom screen shows, and that screen is the map: mode 0's handler func_02021578
// loads data/map/mapname.gp2, and ReloadZoneMinimap nearby builds a path from data/pack_lv5/minimapt.gp2.
// func_020dc214 does the switch through func_02022d78, which blanks the sub
// screen to MASTER_BRIGHT -16 before changing mode and otherwise derives it from the zone id.
// Argument 1 forces it on, 2 clears the override and falls back to the zone-derived mode, 3 takes
// the alternate only when the 0x43 gamemain node and the grotto state have not forced it on.
// The pointer at +0x8 of the zone state is the same ZoneModeFlags LoadCharaSubS202Model tests, and
// it is the low nibble at +0xc of it that has to be 0 for the grotto path to force the map on.
extern "C" ARM void RefreshSubScreenMode(int mode) {
    BattleStruct* battle = GetBattleStruct();
    GrottoStruct* grotto = GetGrottoStruct(battle);
    void* something = GetMultiplayerState(grotto);
    void* ptr = GetZoneState();
    int forceOn;
    int useAlternate;
    ZoneModeFlags* zoneModeFlags = *(ZoneModeFlags**)((char*)ptr + 0x8);

    int base = func_ov017_0218b5b0();
    forceOn = 0;
    void* list = *(void**)(base + 0x3000 + 0x6fc);
    useAlternate = forceOn;

    int listContains = func_02046b60((GameMainNodeList*)list, 0x43);
    if (listContains) {
        forceOn = 1;
    }

    if (grotto->unknown_0[0] != 0 && grotto->unknown_0[1] != 0) {
        if (IsHostOrSinglePlayer(something) != 0 && zoneModeFlags != NULL) {
            if (zoneModeFlags->zoneMode == 0) {
                forceOn = 1;
            }
        }
    }

    if (mode == 1) {
        forceOn = 1;
    } else if (mode == 2) {
        forceOn = 0;
    } else if (mode == 3) {
        useAlternate = 1;
    }

    if (forceOn) {
        func_020dc214(1);
    } else if (useAlternate) {
        func_020dc214(2);
    } else {
        func_020dc214(0);
    }

    func_020941b0((NaviManager*)GetNaviManager());
    ClearGlobalStateFlags((GlobalStateFlags*)GetGlobalStateFlags(), 0x41);
}
