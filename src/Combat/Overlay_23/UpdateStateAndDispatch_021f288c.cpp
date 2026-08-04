#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

extern "C" void func_02046380(void);
int GetGlobalField0x1c020421a0(void);
extern "C" void* func_0205ec34(void);
extern "C" void func_0204500c(void* obj, char* buffer, int a, int b);
extern "C" int func_ov023_021f4438(void* obj);
extern "C" int func_ov023_021f4fc8(void);
int CheckThresholdOverAny_021f5228(int id);
int TestBitInByteArray(int unused, unsigned char* arr, int index);

struct ArrayContainsByteStruct;
int ArrayContainsByte(struct ArrayContainsByteStruct* s, int val);

struct TableA68;
void* FindEntryByKey(struct TableA68* table, int key);

struct StoreStruct;
void StoreInArray0x8b0(struct StoreStruct* base, int index, int value);

struct Reset_021eefac;
void ResetFields_021eefac(struct Reset_021eefac* s);

struct GlobalStateOv023_021ffefc {
    int counter;
    char pad1[0x12 - 4];
    unsigned char flagArr[4];
    char pad2[0x18 - 0x16];
    int id;
};
extern struct GlobalStateOv023_021ffefc* data_ov023_021ffefc;

struct PctBits021f288c { unsigned short low : 7; unsigned short pct : 9; };

// USA: func_ov023_021f288c  (semantic: UpdateStateAndDispatch_021f288c)
extern "C" ARM int func_ov023_021f288c(unsigned char* obj) {
    char msgBuf[0x100];
    struct BattleStruct* battleStruct = GetBattleStruct();
    struct GlobalStateOv023_021ffefc* g = data_ov023_021ffefc;
    int id = g->id;
    int state = GetGlobalField0x1c020421a0();
    unsigned char* stateObj = (unsigned char*)state;
    func_02046380();
    int flag8;
    if (g->counter == 0) {
        char* e1 = (char*)FindEntryByKey((struct TableA68*)(obj + 0x5904), 0xd);
        sprintf(msgBuf, e1);
        char* e2 = (char*)FindEntryByKey((struct TableA68*)(obj + 0x5904), 0x22);
        strcat(msgBuf, e2);
        struct PctBits021f288c* pb = (struct PctBits021f288c*)(obj + id * 0x54 + 0x5700 + 0x9c);
        int percent = pb->pct;
        StoreInArray0x8b0((struct StoreStruct*)stateObj, 0, percent);
        func_0204500c(stateObj, msgBuf, 1, 0xe3);
        stateObj[0x19b2] = 0;
        *(int*)(stateObj + 0x998) = 1;
        g->counter = g->counter + 1;
    } else if (g->counter == 1) {
        void* p2a04 = GetPtrField0x2a04(battleStruct);
        flag8 = 0;
        if (ArrayContainsByte((struct ArrayContainsByteStruct*)p2a04, id)) {
            if (CheckThresholdOverAny_021f5228(id)) {
                flag8 = 1;
                void* base = func_0205ec34();
                if (TestBitInByteArray((int)base, (unsigned char*)base + 0x8c, 0x119c)) {
                    stateObj[0x19ca] = 0;
                }
            }
        }
        int found = 0;
        int i;
        for (i = g->id + 1; i < 4; i++) {
            if (g->flagArr[i] != 0) {
                found = 1;
                break;
            }
        }
        int fieldCheck = func_ov023_021f4438(obj);
        if (found == 0 && fieldCheck == 0 && *(int*)(obj + 0x5768) == 0) {
            stateObj[0x19ae] = 0;
            stateObj[0x19ca] = 0;
            stateObj[0x19af] = 0;
        }
        if (func_ov023_021f4fc8()) {
            ResetFields_021eefac((struct Reset_021eefac*)g);
            return flag8 ? 8 : 7;
        }
    }
    return *(int*)(obj + 0xeac);
}
