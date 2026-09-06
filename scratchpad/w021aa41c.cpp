#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetField5cb0Value(char* obj);
int GetField5cb4Value(char* obj);
int GetField5cb8Value(char* obj);
void SetField5cb0AndRecordByte0(char* obj, int v);
void SetField5cb4AndRecordByte1(char* obj, int v);
void SetSlotByte020107dc(char* base, int val);
void SetBothCounters(void* obj, int value, int frames);
void InitFieldsFromCombatant_0219bcac(unsigned char flag);
extern "C" void* func_ov017_0218b5b0(void);

// USA: func_ov017_021aa41c
ARM void SyncSlotFieldsAndCounters_021aa41c(unsigned short* self) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    int v0 = GetField5cb0Value((char*)battleStruct);
    int v1 = GetField5cb4Value((char*)battleStruct);
    int v2 = GetField5cb8Value((char*)battleStruct);

    unsigned short hVal = self[5];
    int tierA1 = v1 * 100;
    int tierB1 = hVal * 100;
    unsigned short bVal = self[4];
    int tierA2 = v0 * 10000 + tierA1;
    int tierB2 = bVal * 10000 + tierB1;
    unsigned short cVal = self[6];
    int totalA = v2 + tierA2;
    int totalB = cVal + tierB2;

    if (totalA == totalB) {
        SetBothCounters(func_ov017_0218b5b0(), 0, 0x1e);
    } else {
        InitFieldsFromCombatant_0219bcac(0);
    }

    SetField5cb0AndRecordByte0((char*)battleStruct, self[4]);
    SetField5cb4AndRecordByte1((char*)battleStruct, self[5]);
    SetSlotByte020107dc((char*)battleStruct, self[6]);
    *((unsigned char*)self + 1) = 1;
}
