#include <globaldefs.h>

struct BattleStruct* GetBattleStruct(void);
extern "C" void* func_0205ec34(void);
int LookupAndForEachNode020649b0(void* a, int mode, void* c);
extern "C" void func_0206f81c(void* p);
void InitObj_021adc58(unsigned char* self);
unsigned char GetField0x397cValue(struct BattleStruct* battleStruct);
extern "C" int func_02030f30(int angle);
void CopyVec3(int* dst, int* src);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

struct LocalBuf0219922c {
    char pad0[0x20];
    int f0x20;
    char pad1[0x34 - 0x24];
};

// USA: func_ov017_0219922c  (semantic: InitAndAppendSearchNode_0219922c)
extern "C" ARM void func_ov017_0219922c(unsigned char* self) {
    struct BattleStruct* battle = GetBattleStruct();
    unsigned char* search = *(unsigned char**)(self + 0x3000 + 0x6bc);
    int flag = (search[0x16] == 1);
    unsigned short val_b6 = *(unsigned short*)(self + 0x3600 + 0xb6);
    signed short val_c6 = *(signed short*)(self + 0x3600 + 0xc6);

    if (!flag) {
        void* p = func_0205ec34();
        struct LocalBuf0219922c c;
        c.f0x20 = *(unsigned short*)(search + 0x1c);
        if (LookupAndForEachNode020649b0(p, 0x12, &c)) {
            func_0206f81c(&c);
        }
        return;
    }

    unsigned char* node = *(unsigned char**)(self + 0x3000 + 0xb24);
    InitObj_021adc58(node);

    node = *(unsigned char**)(self + 0x3000 + 0xb24);
    node[0xa] = (unsigned char)val_b6;

    int fv = GetField0x397cValue(battle);
    node = *(unsigned char**)(self + 0x3000 + 0xb24);
    node[8] = (unsigned char)fv;

    int angle = val_c6 + 0x3244;
    int r = func_02030f30(angle);
    node = *(unsigned char**)(self + 0x3000 + 0xb24);
    *(unsigned short*)(node + 0x10) = (unsigned short)r;

    node = *(unsigned char**)(self + 0x3000 + 0xb24);
    CopyVec3((int*)(node + 0x14), (int*)search);

    if (search[0x17] == 2) {
        (*(unsigned char**)(self + 0x3000 + 0xb24))[0x20] = 1;
    }

    unsigned char* base3000 = self + 0x3000;
    struct TailList020469b4* list = *(struct TailList020469b4**)(base3000 + 0x6fc);
    struct TailNode020469b4* tail = *(struct TailNode020469b4**)(base3000 + 0xb24);
    AppendNodeToTail(list, tail);
}
