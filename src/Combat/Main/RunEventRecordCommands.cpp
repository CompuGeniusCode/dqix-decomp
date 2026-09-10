#include <globaldefs.h>

struct Node02064530;
struct Obj020649b0 { char pad0[0xc]; void* nodeHead; };

extern "C" struct Obj020649b0* func_02064490(void*, int, void*);
extern "C" int func_02064530(void* a, struct Node02064530* node, void* c);

// func_02064490 picks the first record in the list at +0x47c whose selector byte at +6 matches the
// second argument, then walks that record's +0x10 alternatives and returns the first one whose +8
// condition chain passes in full; its command chain is what runs here. Conditions read
// GetMessageChoiceIndex, GetZoneTransitionRequest and GetPlayerCombatant; the executor at 0x02061c04
// calls RunAttnpcScript, LightingManager::GetInstance and GetActiveCamera -- field events, not
// battle. The wrappers pass 3, 0xf and 0x10; what those three select is not established.
extern "C" ARM int RunEventRecordCommands(void* a, int mode, void* c) {
    struct Obj020649b0* r = func_02064490(a, mode, c);
    if (r == NULL) return 0;
    *(int*)((char*)c + 0x30) = 0;
    return func_02064530(a, (struct Node02064530*)r->nodeHead, c) != 0;
}
