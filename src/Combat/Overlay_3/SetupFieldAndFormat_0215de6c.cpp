#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct StoreStruct;
void StoreInArray0x8b0(struct StoreStruct* base, int index, int value);
void SetByteAtIndex(unsigned char* base, int index, unsigned char value);
void SetByteInRange(unsigned char* base, int index, unsigned char value);
int GetGlobalField0x1c020421a0();
extern "C" void func_02046380(void* global);
int CallFunc020e0434With02153694(int value);
extern "C" void func_02046608(int a, int b, void* fmt, void* dst, int p4, int p5, int p6);

// USA: func_ov003_0215de6c
ARM void SetupFieldAndFormat_0215de6c(char* base, void* buf) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    int field = GetGlobalField0x1c020421a0();
    void* ptr = GetPtrField0x2a04(battleStruct);

    unsigned char flag = *(unsigned char*)(base + 0x3bb);
    int value = *(int*)((char*)ptr + 0xf6c);
    if (flag == 2) {
        value -= *(int*)(base + 0x3cc);
    }

    func_02046380((void*)field);

    StoreInArray0x8b0((struct StoreStruct*)field, 0, value);
    SetByteInRange((unsigned char*)field, 0, 7);
    SetByteAtIndex((unsigned char*)field, 0, 1);

    int fmt = CallFunc020e0434With02153694(0x3f1);
    func_02046608(field, 8, (void*)fmt, buf, 0x100, 0, 0);
}
