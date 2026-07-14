#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int CheckFlag0x6cBit0Clear(unsigned char* obj);
extern "C" int func_02032fdc(void* obj, void* param1, int flag);
int GetField0x3b0Value(struct BattleStruct* battleStruct);
void* GetPtrField0x144(void* obj);
extern "C" void func_020ca528(void* ptr, void* addr);

struct Vec3Block020b3850 { unsigned int v[3]; };
void StoreVec3AndClearFlags020b3850(struct Vec3Block020b3850* src);

struct Vec3Block020b3880 { unsigned int v[3]; };
void StoreVec3AndClearFlags020b3880(struct Vec3Block020b3880* src);

void InvokeHandlerAndClearFlags020b3814(void);

extern "C" void func_02047448(int a, int b, int c);

extern int data_0210a0cc;
struct FlagRegs02076bec { unsigned char pad[0xfc]; unsigned int flags; };
extern struct FlagRegs02076bec data_0210a010;
extern int data_020e8920;

// USA: func_02076bec
ARM int TickActorFlagStateAndDispatch02076bec(unsigned char* obj, void* param1) {
    if (!CheckFlag0x6cBit0Clear(obj)) {
        return 0;
    }

    int result = func_02032fdc(obj, param1, 0);
    if (*(unsigned char*)(obj + 0x17a) == 0) {
        return result;
    }

    struct BattleStruct* battleStruct = GetBattleStruct();
    int f3b0 = GetField0x3b0Value(battleStruct);

    struct Vec3Block020b3850 localBuf = *(struct Vec3Block020b3850*)(obj + 0x44);
    localBuf.v[1] = *(unsigned int*)(obj + 0x170);
    StoreVec3AndClearFlags020b3850(&localBuf);

    if (f3b0 != 0) {
        void* ptr = GetPtrField0x144((void*)f3b0);
        func_020ca528(ptr, &data_0210a0cc);
        data_0210a010.flags &= ~0xa4;
    }

    struct Vec3Block020b3880 localBuf2 = *(struct Vec3Block020b3880*)&data_020e8920;
    StoreVec3AndClearFlags020b3880(&localBuf2);
    InvokeHandlerAndClearFlags020b3814();

    func_02047448(*(int*)(obj + 0x16c), 0, 1);
    return result;
}
