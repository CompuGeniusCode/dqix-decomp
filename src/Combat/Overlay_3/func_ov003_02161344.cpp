#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct IntField0x23c_020a27c4;
int GetFieldIfFlag4(char* obj);
int GetIntAt0x23c(struct IntField0x23c_020a27c4* obj);
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern "C" int func_ov003_02160854(void* obj);

struct Ctx02160a68;
extern "C" int func_ov003_02160a68(struct Ctx02160a68* self);

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);

struct Obj2081;
void CallFunc0204c804OnMatchingKey(struct Obj2081* obj, int key);

struct Obj0208203c;
void ResetWithSub0208203c(struct Obj0208203c* obj);

struct Obj020e25e8;
void ResetSelectionState020e25e8(struct Obj020e25e8* obj);

extern unsigned short data_02114e30;
extern struct Obj0205eaa0 data_02108760;

// USA: func_ov003_02161344
extern "C" ARM int func_ov003_02161344(char* obj) {
    *(void**)(obj + 0x470) = obj + 0x49c;
    int result = 0;
    int flagB = result;

    struct BattleStruct* battle = GetBattleStruct();
    struct IntField0x23c_020a27c4* p = (struct IntField0x23c_020a27c4*)GetFieldIfFlag4((char*)battle);
    if (p != 0 && ((*((unsigned char*)p + 0x244) & 2) != 0 || GetIntAt0x23c(p) == 0)) {
        flagB = (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x200) != 0) ? 1 : 0;
    }

    if (func_ov003_02160854(obj) != 0 || flagB != 0) {
        DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
        result = -1;
        if (*(short*)(obj + 0x49c) == 0x2c) {
            result = 1;
        }
    } else {
        if (func_ov003_02160a68((struct Ctx02160a68*)obj) != 0) {
            result = -1;
        }
    }

    if (result != 0) {
        CallFunc0204c804OnMatchingKey(*(struct Obj2081**)(obj + 0x324), *(short*)(obj + 0x488));
        ResetWithSub0208203c((struct Obj0208203c*)(obj + 0x308));
        *(void**)(obj + 0x470) = 0;
    }

    if (*(void**)(obj + 0x390) != 0 && result != 0) {
        ResetSelectionState020e25e8(*(struct Obj020e25e8**)(obj + 0x390));
    }

    return result;
}
