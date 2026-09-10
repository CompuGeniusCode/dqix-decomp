#include <globaldefs.h>
extern "C" unsigned short* GetActorRecord(int*);

struct Slots0203df78 { char pad0[0xc]; void* items[0x20]; };

// Walks the 32 slots of the field object registry and returns the entry whose id halfword matches,
// skipping empty slots and ones whose flags word has 0x8000 set -- the same liveness test
// GetActorSlot uses. The id is not stored in the entry but in the record it points to at +8, and
// the entries are world actors: ov001 pulls a CombatantStruct out of one at +0x18 and ov017 reads a
// position vector. 12 of the 28 call sites fetch the registry a couple of instructions earlier; the
// rest reuse a cached pointer. func_0203dfdc is the same search returning the slot index instead.
extern "C" ARM void* FindFieldObjectById(void* base, int key) {
    int i;
    for (i = 0; i < 0x20; i++) {
        void* p = ((struct Slots0203df78*)base)->items[i];
        if (p == NULL) continue;
        if (*(int*)p & 0x8000) continue;
        {
            unsigned short* q = GetActorRecord((int*)(p));
            if (q == NULL) continue;
            if (*q == key) return ((struct Slots0203df78*)base)->items[i];
        }
    }
    return NULL;
}
