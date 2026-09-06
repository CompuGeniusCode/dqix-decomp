#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void AddEntryAndIncrementCount0215a88c(void* objRaw, void* listRaw, int c);
void AppendToChainAndIncCount0215fe84(void* obj, void* node, int idx);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);

struct OutStruct0215ccbc;
void PopulateEntry_0215ccbc(int unused, struct OutStruct0215ccbc* out, struct CombatantStruct* combatant,
                             short valC, short valA, short valB, int wordC, int wordD, unsigned char byteE);

// USA: func_ov000_021584e8
ARM void PopulateAndLinkEntry_021584e8(void* obj, void* entry, void* combatant, void* chain, unsigned short idFlag, unsigned char kind) {
    unsigned char* b = (unsigned char*)obj;
    short* stats;
    int local[2];

    AddEntryAndIncrementCount0215a88c(obj, entry, idFlag);
    AppendToChainAndIncCount0215fe84(chain, entry, 1);
    b[0x8000 + 0xe02]++;

    local[0] = 0;
    local[1] = 0;
    func_ov000_02159eac(obj, local, kind);

    stats = *(short**)((char*)combatant + 0x138);
    PopulateEntry_0215ccbc(0, (struct OutStruct0215ccbc*)entry, (struct CombatantStruct*)combatant,
                            0, stats[0], stats[1], local[0], local[1], 0);
}
