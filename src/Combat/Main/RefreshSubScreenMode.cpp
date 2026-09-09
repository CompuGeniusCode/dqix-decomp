#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Grotto/Main/GrottoStruct.h"

extern "C" {
    void* GetMultiplayerState(GrottoStruct* grotto);
    int IsHostOrSinglePlayer(void* something);
    void* GetZoneState(void);
    int func_ov017_0218b5b0(void);
}

struct FlagWord020466f4;
struct ListHead02046b60;
struct Obj020941b0;

struct StructWithNibble020dc2d0 {
    char pad[0xc];
    unsigned char nibbleLo : 4;
    unsigned char nibbleHi : 4;
};

extern "C" void func_020dc214(int mode);
extern "C" int* GetNaviManager(void);
extern "C" void func_020941b0(struct Obj020941b0* p);
extern "C" void* GetGlobalStateFlags(void);
extern "C" void ClearGlobalStateFlags(struct FlagWord020466f4* word, unsigned int mask);
extern "C" int func_02046b60(struct ListHead02046b60* list, int id);

// Recomputes what the bottom screen shows, and that screen is the map: mode 0's handler func_02021578
// loads data/map/mapname.gp2, and ReloadZoneMinimap nearby builds a path from data/pack_lv5/minimapt.gp2.
// func_020dc214 does the switch through func_02022d78, which blanks the sub
// screen to MASTER_BRIGHT -16 before changing mode and otherwise derives it from the zone id.
// Argument 1 forces it on, 2 clears the override and falls back to the zone-derived mode, 3 takes
// the alternate only when the 0x43 gamemain node and the grotto state have not forced it on.
extern "C" ARM void RefreshSubScreenMode(int mode) {
    BattleStruct* battle = GetBattleStruct();
    GrottoStruct* grotto = GetGrottoStruct(battle);
    void* something = GetMultiplayerState(grotto);
    void* ptr = GetZoneState();
    int flag1;
    int flag2;
    StructWithNibble020dc2d0* field8 = *(StructWithNibble020dc2d0**)((char*)ptr + 0x8);

    int base = func_ov017_0218b5b0();
    flag1 = 0;
    void* list = *(void**)(base + 0x3000 + 0x6fc);
    flag2 = flag1;

    int listContains = func_02046b60((ListHead02046b60*)list, 0x43);
    if (listContains) {
        flag1 = 1;
    }

    if (grotto->unknown_0[0] != 0 && grotto->unknown_0[1] != 0) {
        if (IsHostOrSinglePlayer(something) != 0 && field8 != NULL) {
            if (field8->nibbleLo == 0) {
                flag1 = 1;
            }
        }
    }

    if (mode == 1) {
        flag1 = 1;
    } else if (mode == 2) {
        flag1 = 0;
    } else if (mode == 3) {
        flag2 = 1;
    }

    if (flag1) {
        func_020dc214(1);
    } else if (flag2) {
        func_020dc214(2);
    } else {
        func_020dc214(0);
    }

    func_020941b0((Obj020941b0*)GetNaviManager());
    ClearGlobalStateFlags((FlagWord020466f4*)GetGlobalStateFlags(), 0x41);
}
