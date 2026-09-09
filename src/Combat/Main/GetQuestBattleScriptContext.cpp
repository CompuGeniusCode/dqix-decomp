#include <globaldefs.h>

extern void* data_02109d88;

// Returns the singleton at data_02109d88. Its only writer, func_0209fd64, is called once from
// ov023 right after that overlay loads data/scenario/quest_btl_%d.stb (the ROM holds quest_btl.stb
// alongside quest_btl_1 through _4), and it parks the script bytes and length at +8 and +0xc and
// registers the 0x31-entry opcode table at 0x020f1758, seemingly building a VM over the data. All
// 35 callers are handlers in that table and each bails out with 0 when this returns null. Whether
// the class also drives the other .stb scripts in data/scenario is not established.
extern "C" ARM void* GetQuestBattleScriptContext() {
    return data_02109d88;
}
