#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);
void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalBuf021ccc34 {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned char bits0_2 : 3;
    unsigned char bit3 : 1;
    unsigned char rest : 4;
    unsigned char data[15];
};

struct Table464View021ccc34 {
    char pad[0x464];
    unsigned char b;
};

// USA: func_ov017_021ccc34  (semantic: SendField464Chunks_021ccc34)
extern "C" ARM void func_ov017_021ccc34(int combatantId) {
    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* c = GetCombatantWithFlag0x100(bs, combatantId);
    if (!c) return;
    int field150 = GetFieldAt0x150((unsigned char*)c);
    if (!field150) return;

    void* p = GetData02100044();
    struct LocalBuf021ccc34 buf;
    unsigned char x = (unsigned char)combatantId;
    buf.tag = 0xe;
    buf.bits0_2 = x;
    buf.bit3 = 0;
    int i;
    for (i = 0; i < 15; i++) {
        buf.data[i] = *(unsigned char*)((char*)field150 + 0x464 + i);
    }
    func_0205e330(p, &buf, 0);

    buf.bit3 = 1;
    for (i = 0; i < 12; i++) {
        struct Table464View021ccc34* p2 = (struct Table464View021ccc34*)((char*)field150 + (i + 15));
        buf.data[i] = p2->b;
    }
    func_0205e330(p, &buf, 0);
}
