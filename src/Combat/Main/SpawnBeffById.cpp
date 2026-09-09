#include <globaldefs.h>

extern "C" void* func_02057f8c(void* list, int id);
extern "C" void func_02057fd8(void* a1, void* node, int a3);

// Looks up the loaded .beff record with this id and starts an instance of it, returning the slot
// index or -1 when none is free. func_02057de0 allocates each record as 0x1f0 bytes, parses it at
// 0x020553ec -- which walks an "ARC" archive for the member whose name contains ".beff" -- and
// links it onto the list at data_021079ec; func_02057fd8 then claims one of that object's sixteen
// 0xd4-byte slots and registers it in the combatant list at index 0xd0 + slot. Every .beff member
// found sits in a data/effect/b######.chr or btarc.nsarc archive, so battle effect is likely.
extern "C" ARM void SpawnBeffById(void* list, int id, int a3) {
    void* node = func_02057f8c(list, id);
    func_02057fd8(list, node, a3);
}
