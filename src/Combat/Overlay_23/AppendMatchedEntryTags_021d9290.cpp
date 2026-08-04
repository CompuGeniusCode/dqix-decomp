#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

struct Container020e0310;
int GetFieldByKey020e0434(Container020e0310*, int);
int GetGlobalField0x1c020421a0(void);
extern "C" int func_020420e8(void*, int);
int AppendXTag(char*, int);
int AppendHeightTag(char*, int);
int AppendFormatted02041fac(char*, int, int);
extern "C" void func_0200f374(void*, int);
void* Find_021d994c(void*, int);
int AppendString02042058(char*, const char*);
extern "C" void func_02046380(int);
ARM void InitObjFromCombatantId020e4bf4(void*, int);
int ApplyEqual12Flag020426a4(int, int);
struct StoreStruct;
void StoreInArray0x8b0(struct StoreStruct*, int, int);
extern "C" void func_02046608(int, int, void*, void*, int, int, int);
int AppendXYTag(char*, int, int);
extern "C" int sprintf(char*, const char*, ...);

struct EntryLocal_021d9290 {
    void* f0;
    void* f4;
    int f8;
};

// USA: func_ov023_021d9290  (semantic: AppendMatchedEntryTags_021d9290)
extern "C" ARM void func_ov023_021d9290(char* obj, char* buf, unsigned char count) {
    if (!buf) return;

    GetBattleStruct();
    int g = GetGlobalField0x1c020421a0();

    char* fieldStr = (char*)GetFieldByKey020e0434(*(Container020e0310**)(obj + 0x0), 0x75f8);
    int len = func_020420e8(fieldStr, 0);
    AppendXTag(buf, (0xc0 - len) >> 1);
    AppendHeightTag(buf, 1);
    AppendFormatted02041fac(buf, (int)fieldStr, 0x10);

    unsigned char* idArr = (unsigned char*)(obj + 0x124);
    int a2 = *(signed short*)(obj + 0xc2);
    int b = *(unsigned char*)(obj + 0x119);
    int loopCount = *(unsigned char*)(obj + 0x128);
    int found = 0;
    signed char adj = (signed char)(((a2 << 3) - (b * 10 + 0x1d)) / (b - 1));
    int total8 = a2 << 3;

    if (*(int*)(obj + 0x120) == 0) return;

    char* fieldStr2 = (char*)GetFieldByKey020e0434(*(Container020e0310**)(obj + 0x0), 0x75f9);
    int i;
    for (i = 0; i < loopCount; i++) {
        if (*(int*)(obj + i * 4 + 0xdc) != 0 && count != 0) {
            int id = idArr[i];
            void* entry = Find_021d994c(obj, id);
            if (entry != NULL) {
                char buf1[0x100];
                char buf2[0x100];
                func_0200f374(buf1, 0x100);
                func_0200f374(buf2, 0x100);
                if (found != 0) {
                    char* fieldStr0 = (char*)GetFieldByKey020e0434(*(Container020e0310**)(obj + 0x0), 0);
                    AppendString02042058(buf, fieldStr0);
                    AppendHeightTag(buf, adj);
                }
                func_02046380(g);
                struct EntryLocal_021d9290 local;
                InitObjFromCombatantId020e4bf4(&local, id);
                void* val = (char*)entry + 8;
                local.f0 = val;
                local.f4 = val;
                *(void**)(g + 0x10) = &local;
                int addrAsInt = (int)obj + i * 4 + 0xdc;
                int applyResult = ApplyEqual12Flag020426a4(8, *(int*)addrAsInt);
                sprintf(buf2, fieldStr2, 0x94 - applyResult);
                StoreInArray0x8b0((struct StoreStruct*)g, 1, *(int*)(obj + 0xdc + i * 4));
                func_02046608(g, 0xa, buf2, buf1, 0x100, 0, 0);
                AppendString02042058(buf, buf1);
                found = 1;
                count = count - 1;
            }
        }
    }

    if (found == 0) {
        char* fieldStr3 = (char*)GetFieldByKey020e0434(*(Container020e0310**)(obj + 0x0), 0x75fa);
        int len3 = func_020420e8(fieldStr3, 0);
        len3 = 0xc0 - len3;
        AppendXYTag(buf, len3 >> 1, (total8 - 0x1a) / 2 + 0x10);
        AppendString02042058(buf, fieldStr3);
    }
}
