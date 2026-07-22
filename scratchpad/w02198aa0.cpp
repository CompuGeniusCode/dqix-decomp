#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Grotto/Main/GrottoStruct.h"
#include "Grotto/Overlay_17/Struct44C8.h"

struct SearchStruct;
extern "C" void* func_0202ae18(void);
extern "C" void* func_02012fe4(void);
extern "C" int func_0202c540(void* p);
extern "C" void func_ov017_0219b33c(void* obj, void* header);
extern "C" void func_ov017_0219e310(void* obj, int flag);
extern "C" void func_ov017_021be0a0(void* obj);

struct CombatantStruct;
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
int GetField0x3b0Value(struct BattleStruct* battleStruct);
int GetGlobalField0x1c020421a0(void);
int CheckSubstructByte0x7cPositive(signed char* obj);
struct U16Field0x6_020375f8;
unsigned short GetU16At0x6(struct U16Field0x6_020375f8* obj);
int CheckField0x14Or0x20Positive(int* obj);

struct BitField0203402c;
int CheckField0xc4Low15BitsNonZero(struct BitField0203402c* p);
int CheckField0NonZero(int* obj);

struct Vec3copy0202ec84 { unsigned int v[3]; };
int ComputeTwoFromVec3_0202ec84(void* obj, struct Vec3copy0202ec84* src, int* out1, int* out2);

void InitObj0219a674(unsigned char* self);
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);

void MaybeClearGrottoState0201bfd4(void);
void* GetField0x3f8Address(struct BattleStruct* battleStruct);
void InitStruct02070378(char* obj);
void* CallFunc0200fbb4AtField0x3f8(void* obj);

struct TailNode020469b4 { unsigned char pad0[2]; unsigned char inList; unsigned char pad3; void* next; };
struct TailList020469b4 { void* head; void* tail; };
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

extern unsigned short data_02114e30;
extern unsigned char data_02114e54;

// USA: func_ov017_02198aa0
extern "C" ARM void NotifyGrottoEntranceIfInRange_02198aa0(void* obj) {
    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* c1 = GetCombatantAtField0x397c(bs);
    int f3b0 = GetField0x3b0Value(bs);
    struct Struct_ov017_44C8* ov = func_ov017_0218b5b0();
    int g = GetGlobalField0x1c020421a0();
    struct SearchStruct* s = (struct SearchStruct*)func_0202ae18();
    void* v = func_02012fe4();
    struct GrottoStruct* grotto = GetGrottoStruct(bs);
    int discState = (int)grotto->activeMapData.GetDiscoveryState() & 0xff;
    int mapType = (int)grotto->activeMapData.GetMapType() & 0xff;
    int envr = grotto->activeEnviron;

    if (CheckSubstructByte0x7cPositive((signed char*)c1) != 0) return;
    if (*(unsigned char*)grotto == 0) return;
    if (grotto->entranceZoneId != GetU16At0x6((struct U16Field0x6_020375f8*)c1) || *(int*)((char*)g + 0x9a0) != 0) return;
    if (CheckField0x14Or0x20Positive((int*)ov) != 0) return;
    if (CheckField0xc4Low15BitsNonZero((struct BitField0203402c*)c1) != 0) return;

    if (discState != 2 && discState != 3) {
        if (CheckField0NonZero((int*)s) != 0) {
            if (func_0202c540(s) != 0) return;
        }
    }

    int entranceX = grotto->entranceX;
    int entranceY = grotto->entranceY;
    int entranceZ = grotto->entranceZ;
    int posX = *(int*)((char*)c1 + 0x44);
    int posY = *(int*)((char*)c1 + 0x48);
    int posZ = *(int*)((char*)c1 + 0x4c);
    if (!(posX > entranceX - 9830 && posX < entranceX + 9830 &&
          posZ > entranceZ - 9830 && posZ < entranceZ + 9830 &&
          posY > entranceY - 0x1000 && posY < entranceY + 0x1000)) {
        return;
    }

    unsigned char local[0x14];
    InitObj0219a674(local);
    local[0] = 4;
    func_ov017_0219b33c(obj, local);

    int flag = TestFlag0SetAndFlag1Clear(&data_02114e30, 1) != 0;
    int a = -1, b = -1;
    if (*((unsigned char*)&data_02114e54 + 0x54) != 0) {
        if (*(unsigned int*)((char*)&data_02114e54 + 0x44) < 0xa) {
            a = *(int*)((char*)&data_02114e54 + 0x38);
            b = *(int*)((char*)&data_02114e54 + 0x3c);
        }
    }

    int out1, out2;
    ComputeTwoFromVec3_0202ec84((void*)f3b0, (struct Vec3copy0202ec84*)((char*)c1 + 0x44), &out1, &out2);

    if (a > 0x70 && a < 0x90 && b > 0x28 && b < 0x60) {
        flag = 1;
    } else if (a > out1 - 0xc && a < out1 + 0xc && b > out2 - 0xc && b < out2 + 0xc) {
        flag = 0;
    }

    if (!flag) return;

    if (discState == 2 || discState == 3) {
        MaybeClearGrottoState0201bfd4();
        char* hdr = (char*)GetField0x3f8Address(bs);
        InitStruct02070378(hdr);
        hdr[7] = 1;
        hdr[0xc] = 1;
        if (mapType == 2) {
            unsigned short v2;
            switch (envr) {
                case 1: v2 = 0xa08d; break;
                case 2: v2 = 0xa0f1; break;
                case 3: v2 = 0xa155; break;
                case 4: v2 = 0xa1b9; break;
                case 5: v2 = 0xa21d; break;
                default: v2 = 0xa08d; break;
            }
            *(unsigned short*)hdr = (unsigned short)(v2 + (short)(signed char)*((unsigned char*)grotto + 8));
            *(unsigned short*)(hdr + 0x1c) = 0x323d;
        } else {
            *(unsigned short*)hdr = 0x9c41;
        }
        CallFunc0200fbb4AtField0x3f8(bs);

        struct TailList020469b4* list = *(struct TailList020469b4**)((char*)ov + 0x3000 + 0x6fc);
        struct TailNode020469b4* node = *(struct TailNode020469b4**)((char*)ov + 0x3000 + 0x70c);
        func_ov017_0219e310(node, 0);
        AppendNodeToTail(list, node);
    } else {
        struct TailList020469b4* list = *(struct TailList020469b4**)((char*)obj + 0x3000 + 0x6fc);
        struct TailNode020469b4* node = *(struct TailNode020469b4**)((char*)ov + 0x3000 + 0xb64);
        func_ov017_021be0a0(node);
        AppendNodeToTail(list, node);
    }
}
