#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void SetField5cb0AndRecordByte0(char* obj, int v);
void SetField5cb4AndRecordByte1(char* obj, int v);
void SetSlotByte020107dc(char* base, int val);

// USA: func_0206df14
ARM void ApplySlotBytesToBattleStruct(unsigned char* obj) {
    struct BattleStruct* bs = GetBattleStruct();
    SetField5cb0AndRecordByte0((char*)bs, (obj + obj[0x332] * 0x1c)[0]);
    SetField5cb4AndRecordByte1((char*)bs, (obj + obj[0x332] * 0x1c)[1]);
    SetSlotByte020107dc((char*)bs, (obj + obj[0x332] * 0x1c)[2]);
}
