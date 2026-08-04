#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" struct CombatantStruct* func_ov023_021e8f28(int index);
extern "C" int func_ov017_021d60f4(void* obj);
extern "C" void func_ov017_021d6134(void* obj, int value);

// USA: func_ov023_021e9424  (semantic: CheckSequenceMatchAndFlag_021e9424)
extern "C" ARM int func_ov023_021e9424(char* ptr, int n) {
    GetBattleStruct();
    int id0 = func_ov017_021d60f4(ptr);
    ptr += 8;
    struct CombatantStruct* combatant = func_ov023_021e8f28(id0);
    if (!combatant) return 0;

    int allMatch = 1;
    int i;
    for (i = 0; i < n - 2; i += 2) {
        int val1 = func_ov017_021d60f4(ptr);
        char* arg2 = ptr + 8;
        ptr += 0x10;
        int val2 = func_ov017_021d60f4(arg2);
        int tableAddr = *(int*)((char*)combatant + 0x150) + 0x194;
        unsigned char idx = (unsigned char)val1;
        int entryAddr = tableAddr + (idx << 5);
        short expected = *(short*)(entryAddr + 0x18);
        if (expected != val2) allMatch = 0;
    }

    if (allMatch != 0) {
        func_ov017_021d6134(ptr, 1);
    } else {
        func_ov017_021d6134(ptr, 0);
    }
    return 1;
}
