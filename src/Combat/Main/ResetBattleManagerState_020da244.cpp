#include <globaldefs.h>

struct SlotEntry020da244 {
    unsigned char pad0[8];
    int field8;
};

struct BattleManagerCtx020da244 {
    void* f0;
    int f4;
    unsigned char pad8[0xc - 0x8];
    unsigned char fc;
    unsigned char fd;
    unsigned char fe;
    unsigned char ff;
    unsigned char pad10[0x14 - 0x10];
    SlotEntry020da244 slots[4];
};

extern "C" void _Z24RunCombatFlagStateActionPv(void* ctx);
extern "C" int _Z21GetData02104304Field4v(void);
extern "C" void func_020301c8(int commandId, int flag);
extern "C" void _Z19ResetFields020da2e4Ph(unsigned char* entry);
extern "C" void _ZN13SafeAllocator7DestroyEv(void* self);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void* self);

// USA: func_020da244  (semantic: ResetBattleManagerState_020da244)
extern "C" ARM void func_020da244(BattleManagerCtx020da244* sb) {
    _Z24RunCombatFlagStateActionPv(sb);
    SlotEntry020da244* entry = sb->slots;
    int commandId = _Z21GetData02104304Field4v();
    if (commandId != 0) {
        for (unsigned char i = 0; i < 4; i++, entry++) {
            if (entry->field8 != -1) {
                func_020301c8(commandId, entry->field8 != -1);
                _Z19ResetFields020da2e4Ph((unsigned char*)entry);
            }
        }
    }
    if (sb->f0 != 0) {
        _ZN13SafeAllocator7DestroyEv(sb->f0);
        _ZN13SafeAllocator21ResetAllocatorPointerEv(sb->f0);
    }
    sb->f0 = 0;
    sb->f4 = 0;
    sb->fc = 0;
    sb->fd = 0;
    sb->fe = 0;
    sb->ff = 0;
}
