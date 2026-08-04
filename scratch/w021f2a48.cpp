#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct BattleStruct* GetBattleStruct(void);
int GetGlobalField0x1c020421a0(void);
extern "C" void func_02046380(void);

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);
int TestBitAt0x34(unsigned char* obj, unsigned int index);
unsigned char CopyOutRegion0x571d(char* obj, void* dst);

struct BinarySearchByComparatorStruct;
void* SearchWithComparator0206f4f0(struct BinarySearchByComparatorStruct* base, int key);

void* Clear12Bytes020e46c4(void* p);

struct Words3 { unsigned int a, b, c; };
extern "C" void func_ov023_021ed804(void* obj, unsigned int a, unsigned int b, unsigned int c);
void SetWords_021edf38_021edf38(void* obj, struct Words3* src);

void DispatchIfCountPositive020dcf7c(int count, void* buf);
extern "C" void func_0200f374(void* buf, int len);

struct TableA68;
void* FindEntryByKey(struct TableA68* table, int key);
extern "C" int sprintf(char* dst, const char* src);
extern "C" char* strcat(char* dst, const char* src);

void InitObjFromCombatantId020e4bf4(void* obj, int combatantId);
void InitObjFromCombatant020e4c74(void* obj, struct CombatantStruct* combatant);

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern "C" void func_0204500c(void* obj, char* buffer, int a, int b);

struct Flags_021ed7e0 {
    unsigned int fieldA : 10;
    unsigned int fieldB : 1;
    unsigned int fieldC : 7;
    unsigned int fieldD : 7;
    unsigned int rest : 7;
};
void ClearFlagBits10to24_021ed7e0(struct Flags_021ed7e0* s);
int CopyIndexedRegion0x75f0(void* unused, short* indices, int* dest, int count);
extern "C" void func_020abe84(void* unused, short* a, int* b, int c);

extern "C" int func_ov023_021f4fc8(void);

extern int* data_ov023_021ffefc;
extern int data_02108760;

struct RowEntry021f2a48 {
    unsigned short word0;
    unsigned short mag : 15;
    unsigned short flag : 1;
    unsigned char pad5;
    signed char last;
};

// USA: func_ov023_021f2a48
ARM int UpdateCombatMessageState_021f2a48(void* objRaw) {
    unsigned char* obj = (unsigned char*)objRaw;
    struct BattleStruct* battleStruct = GetBattleStruct();
    int* g = data_ov023_021ffefc;
    unsigned char* stateObj = (unsigned char*)GetGlobalField0x1c020421a0();
    func_02046380();

    if (*g == 0) {
    *(signed char*)((char*)g + 0xe4) = *(signed char*)((char*)g + 0xe4) + 1;
    signed char e4 = *(signed char*)((char*)g + 0xe4);
    unsigned char val1 = *(unsigned char*)(obj + 0x5900);
    if (val1 <= e4) {
        return 0xe;
    }

    signed char e4c = *(signed char*)((char*)g + 0xe4);
    struct RowEntry021f2a48* row = (struct RowEntry021f2a48*)(obj + 0x58d0 + e4c * 6);
    int mag = row->mag;
    unsigned short word0Val = row->word0;
    signed char rowLast = row->last;

    unsigned char idBuf[4];
    CopyOutRegion0x571d((char*)battleStruct, idBuf);

    struct CombatantStruct* found = 0;
    int i;
    for (i = 0; i < 4; i++) {
        struct CombatantStruct* combatant = GetCombatantFromList(battleStruct, idBuf[i]);
        if (combatant == NULL) continue;
        if (!TestBitAt0x34(*(unsigned char**)(obj + 0x2a0), idBuf[i])) continue;
        if (*(int*)(*(void**)((char*)combatant + 0x130)) & 1) continue;
        found = GetCombatantWithFlag0x800(battleStruct, idBuf[i]);
        break;
    }
    if (found == 0) {
        return *(int*)(obj + 0xeac);
    }

    void* searchResult = SearchWithComparator0206f4f0((struct BinarySearchByComparatorStruct*)(*(unsigned char**)(obj + 0x2a0) + 0x678), (short)mag);
    if (searchResult == 0) {
        return *(int*)(obj + 0xeac);
    }

    struct Words3 bufZero;
    Clear12Bytes020e46c4(&bufZero);
    struct Words3 outputA;
    func_ov023_021ed804(&outputA, bufZero.a, bufZero.b, bufZero.c);
    SetWords_021edf38_021edf38(&bufZero, &outputA);
    *(void**)(stateObj + 0x20) = &bufZero;

    char buf80a[0x80];
    func_0200f374(buf80a, 0x80);
    char buf80b[0x80];
    func_0200f374(buf80b, 0x80);
    struct Words3 localC;
    Clear12Bytes020e46c4(&localC);
    localC.b = (unsigned int)buf80a;
    localC.a = (unsigned int)buf80b;
    DispatchIfCountPositive020dcf7c((short)word0Val, &localC);
    *(void**)(stateObj + 0x18) = &localC;

    char msgBuf[0x200];
    func_0200f374(msgBuf, 0x200);

    if (rowLast >= 0) {
        struct CombatantStruct* c100 = GetCombatantWithFlag0x100(battleStruct, rowLast);
        char* keyStr = (char*)FindEntryByKey((struct TableA68*)(obj + 0x5904), 0x25);
        sprintf(msgBuf, keyStr);
        struct Words3 objA;
        InitObjFromCombatantId020e4bf4(&objA, rowLast);
        *(void**)(stateObj + 0) = &objA;
    } else {
        char keyBuf[0x164];
        func_0200f374(keyBuf, 0x164);
        char* keyStr = (char*)FindEntryByKey((struct TableA68*)(obj + 0x5904), 0x11);
        sprintf(msgBuf, keyStr);
        struct Words3 objA;
        InitObjFromCombatant020e4c74(&objA, found);
        *(void**)(stateObj + 0x10) = &objA;
        if (*(int*)((char*)g + 4) == 0) {
            char* k2 = (char*)FindEntryByKey((struct TableA68*)(obj + 0x5904), 0x12);
            sprintf(keyBuf, k2);
        } else {
            char* k2 = (char*)FindEntryByKey((struct TableA68*)(obj + 0x5904), 0x13);
            sprintf(keyBuf, k2);
        }
        strcat(msgBuf, keyBuf);
        if (*(signed char*)((char*)g + 0xe4) < *(unsigned char*)(obj + 0x5900) - 1) {
            char* k22 = (char*)FindEntryByKey((struct TableA68*)(obj + 0x5904), 0x22);
            strcat(msgBuf, k22);
        }
    }

    DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 0x15, 0);
    func_0204500c(stateObj, msgBuf, 1, 0xe3);
    stateObj[0x19b2] = 0;
    *(int*)(stateObj + 0x998) = 1;

    if (*(unsigned char*)(obj + 0x5000 + e4c * 6 + 0x8d4) != 0) {
        struct Flags_021ed7e0 flags;
        ClearFlagBits10to24_021ed7e0(&flags);
        short shortField = *(short*)((char*)searchResult + 0x10);
        short local10 = shortField;
        int idxRes = CopyIndexedRegion0x75f0(0, &local10, (int*)&flags, 1);
        if (idxRes != 0) {
            unsigned char mode = *(unsigned char*)(obj + 0x5000 + e4c * 6 + 0x8d4);
            if (mode == 1) {
                unsigned int v = *(unsigned int*)&flags;
                unsigned int scaled = (v << 0xe) >> 0x19;
                scaled = scaled + 1;
                if (scaled > 0x63) scaled = 0x63;
                v = (v & ~0x3f800) | (scaled << 0xe);
                *(unsigned int*)&flags = v;
            } else if (mode == 2) {
                unsigned int v = *(unsigned int*)&flags;
                unsigned int scaled = (v << 7) >> 0x19;
                scaled = scaled + 1;
                if (scaled > 0x63) scaled = 0x63;
                v = (v & ~0x1fc0000) | (scaled << 7);
                *(unsigned int*)&flags = v;
            }
            func_020abe84(0, &local10, (int*)&flags, 1);
        }
    }

    (*g) = (*g) + 1;
    } else if (*g == 1) {
        if (func_ov023_021f4fc8() != 0) {
            *g = 0;
        }
    }
    return *(int*)(obj + 0xeac);
}
