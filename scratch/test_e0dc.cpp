#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

union Value_0215e0dc { int i; float f; };
struct TaggedValue_0215e0dc { int type; Value_0215e0dc value; };

extern "C" float func_ov017_021d6110(TaggedValue_0215e0dc* a);
extern "C" int func_02030f30(int angle);
int GetField0x3b0Value(struct BattleStruct* battleStruct);
void SetField0x7cClearFields0x1ec0x1ee(unsigned char* obj, unsigned short val);

// USA: func_ov001_0215e0dc
ARM int ScaleAndWrapAngleField_0215e0dc(TaggedValue_0215e0dc* obj) {
    unsigned char* field = (unsigned char*)GetField0x3b0Value(GetBattleStruct());
    float f = func_ov017_021d6110(obj);
    int fixedVal = (int)(4096.0f * f);
    SetField0x7cClearFields0x1ec0x1ee(field, (short)func_02030f30((int)(((long long)fixedVal * 71u + 0x800) >> 12)));
    return 1;
}
