#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);

int GetGlobalField0x1c020421a0();
extern "C" void func_02046380(void* obj);
int CallFunc020e0434With02153694(int value);
int AppendString02042058(char* dst, const char* src);

struct StoreStruct;
void StoreInArray0x8b0(struct StoreStruct* base, int index, int value);
void SetByteInRange(unsigned char* base, int index, unsigned char value);
void SetByteAtIndex(unsigned char* base, int index, unsigned char value);

extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);

// USA: func_ov003_0215b478
extern "C" ARM void func_ov003_0215b478(unsigned char* self) {
    struct BattleStruct* battle = GetBattleStruct();
    int field = GetGlobalField0x1c020421a0();

    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(self + 0xf4), 0, 2);

    *(short*)(self + 0x100 + 0x94) = 0xb;
    *(short*)(self + 0x100 + 0x96) = 2;
    *(short*)(self + 0x100 + 0x98) = 0x14;
    *(short*)(self + 0x100 + 0x9a) = 0;
    *(short*)(self + 0x100 + 0x9c) = 0x10;
    *(short*)(self + 0x100 + 0x9e) = 2;
    *(short*)(self + 0x100 + 0xa0) = 0xa;
    *(short*)(self + 0x100 + 0xa2) = 0xe;
    self[0x1a5] = 0;
    self[0x1a9] = 1;

    memset(*(void**)(self + 0x7c), 0, 0x960);

    int msg = CallFunc020e0434With02153694(0x3f1);
    AppendString02042058((char*)*(void**)(self + 0x7c), (const char*)msg);

    func_02046380((void*)field);

    void* ptr = GetPtrField0x2a04(battle);
    int value = *(int*)((char*)ptr + 0xf6c);
    StoreInArray0x8b0((struct StoreStruct*)field, 0, value);
    SetByteInRange((unsigned char*)field, 0, 7);
    SetByteAtIndex((unsigned char*)field, 0, 1);

    func_0205d304(self + 0xf4, *(void**)(self + 0x7c), 0, 0, 0, 1, 0, 0);
}
