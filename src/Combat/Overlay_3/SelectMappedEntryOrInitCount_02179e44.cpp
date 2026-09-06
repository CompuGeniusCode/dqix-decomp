#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

short FindMappedMemberId02080468(void* obj, int id);
struct S_a0b8c;
int CountNonZeroValues020a0b8c(struct S_a0b8c* p);

// USA: func_ov003_02179e44  (semantic: SelectMappedEntryOrInitCount_02179e44)
extern "C" ARM int func_ov003_02179e44(char* obj) {
    struct BattleStruct* battle = GetBattleStruct();
    void* ptr = GetPtrField0x2a04(battle);
    int state = *(int*)(obj + 0x1030);
    void* field89c = *(void**)(obj + 0x89c);
    int type;
    switch (state) {
        case 1: type = 0x11; break;
        case 2: type = 0x12; break;
        case 3: type = 0x13; break;
        case 4: type = 0x14; break;
    }

    *(char*)(obj + 0x1043) = -1;
    short idx = FindMappedMemberId02080468(field89c, type);
    short v10 = *(short*)(obj + 0x1010);
    int state2 = *(int*)(obj + 0x1030);
    short diff = (short)(v10 - idx);
    if (state2 > diff) {
        int val = *(int*)(obj + 0x101c + diff * 4);
        *(char*)(obj + 0x1043) = (char)val;
        *(short*)(obj + 0x1014) = 0;
        *(short*)(obj + 0x1016) = 1;
        return 1;
    } else {
        int count = CountNonZeroValues020a0b8c((struct S_a0b8c*)ptr);
        int n = (count + 7) / 8;
        *(short*)(obj + 0x1014) = 0;
        *(short*)(obj + 0x1016) = n;
        short v16 = *(short*)(obj + 0x1016);
        if (v16 == 0) {
            v16 = 1;
            *(short*)(obj + 0x1016) = v16;
        }
        return v16;
    }
}
