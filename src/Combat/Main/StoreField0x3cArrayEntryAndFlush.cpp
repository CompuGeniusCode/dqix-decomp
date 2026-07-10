#include <globaldefs.h>

extern "C" void func_020d21f8(void);
extern "C" void func_020d220c(void);
void CleanDataCacheRange(int addr, int size);

struct SlotArray020d2eb8 { unsigned char pad[0x3c]; int entries[1]; };

// USA: func_020d2eb8
ARM void StoreField0x3cArrayEntryAndFlush(struct SlotArray020d2eb8* obj, int index, int value) {
    func_020d21f8();
    obj->entries[index] = value;
    CleanDataCacheRange((int)&obj->entries[index], 4);
    func_020d220c();
}
