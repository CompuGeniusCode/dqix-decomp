#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_0202ae18(void);
void* GetData02100044(void);

struct SearchStruct;
extern int TestFlagBitAt0xe(struct SearchStruct* obj, int value);

struct CheckField0AndGlobalHalfStruct0202c508;
extern "C" int func_0202c508(struct CheckField0AndGlobalHalfStruct0202c508* obj);

extern void EnqueueEventTag173_021d1810(unsigned short a, unsigned short b, unsigned char c);
extern int* GetGlobal02109030(void);
extern "C" void func_02094030(int* a, unsigned short b, short c, unsigned char d);
extern void RemoveSearchEntry0202c21c(struct SearchStruct* obj, int value);

extern int GetField0x3b4Value(struct BattleStruct* battleStruct);
extern "C" void func_0202b0f4(void* p);
extern "C" void func_ov003_02171e1c(void*, void*);
extern int CheckSlotsAllFree0205e488(void* obj);

// USA: func_ov003_02171764
extern "C" ARM void func_ov003_02171764(char* self) {
    struct BattleStruct* battle = GetBattleStruct();
    struct SearchStruct* search = (struct SearchStruct*)func_0202ae18();
    void* dataPtr = GetData02100044();

    if (TestFlagBitAt0xe(search, *(unsigned char*)(self + 0x199)) != 0) {
        if (func_0202c508((struct CheckField0AndGlobalHalfStruct0202c508*)search) != 0) {
            ((void(*)(unsigned short, short, unsigned char))EnqueueEventTag173_021d1810)(4, -1, 0);
            int* g = GetGlobal02109030();
            func_02094030(g, 4, -1, 0);
        }
        RemoveSearchEntry0202c21c(search, *(unsigned char*)(self + 0x199));
    }

    int fieldVal = GetField0x3b4Value(battle);
    *(int*)(self + 0x72c) = fieldVal;
    if ((unsigned int)fieldVal > 0xbb8) {
        func_0202b0f4(search);
        self[0] = 4;
        return;
    }

    if (*(int*)(self + 0x720) != 0 && *(int*)(self + 0x71c) != 0) {
        func_ov003_02171e1c(self, self + 0x2ae);
        func_0202b0f4(search);
        self[0] = 4;
    }

    if (CheckSlotsAllFree0205e488(dataPtr) != 0) {
        *(int*)(self + 0x720) = 1;
    }
}
