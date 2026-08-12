#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int IsField0Null(void** obj);
extern "C" void* func_02012fe4(void);
int GetField0x3b0Value(struct BattleStruct* battleStruct);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
int CheckSubstructByte0x7cPositive(signed char* obj);
void* GetPointerFromArray0x3c(unsigned char* obj, unsigned int index);
extern "C" int func_02094b9c(void* a, void* b);
extern "C" int func_02030f30(int angle);
void InitObj0219a674(unsigned char* self);
void BuildAndForwardVec_0218da48(void* obj, int angle, int c, int d, unsigned char e);
struct Vec3 { int x, y, z; };
short GetAngleDeltaBetween_021a4700(struct Vec3* p0, int baseAngle, struct Vec3* p2);
extern "C" void func_ov017_0219b33c(void* obj, void* eventBuf);

struct FilterData021983e0 {
    int a, b, c;
};

struct TargetNode021983e0 {
    unsigned char pad0[0x20];
    short angle;
    unsigned char pad1[0x70 - 0x22];
    struct TargetNode021983e0* next;
};

struct EventBuf021983e0 {
    unsigned char tag;
    unsigned char pad1;
    unsigned short pad2;
    unsigned char flag;
    unsigned char pad3[3];
    void* ptr;
    int pad4;
    short field10;
    unsigned short pad6;
};

// USA: func_ov017_021983e0  (semantic: FindFirstTargetAndForward_021983e0)
extern "C" ARM void func_ov017_021983e0(unsigned char* obj) {
    if (IsField0Null(*(void***)(obj + 0x36fc))) {
        struct BattleStruct* bs = GetBattleStruct();
        void* cache = func_02012fe4();
        GetField0x3b0Value(bs);
        struct CombatantStruct* c = GetCombatantAtField0x397c(bs);
        if (CheckSubstructByte0x7cPositive((signed char*)c) == 0) {
            struct FilterData021983e0 filter = *(struct FilterData021983e0*)((char*)c + 0x44);
            struct TargetNode021983e0* node = (struct TargetNode021983e0*)GetPointerFromArray0x3c((unsigned char*)cache + 0x6c, 5);
            while (node != NULL) {
                if (func_02094b9c(node, &filter) != 0) {
                    int angle = (short)func_02030f30(node->angle + 0x3244);
                    BuildAndForwardVec_0218da48(obj, angle, 0xccc, 0x800 - 0xccc, 0);
                    struct EventBuf021983e0 buf;
                    InitObj0219a674((unsigned char*)&buf);
                    buf.tag = 7;
                    buf.ptr = node;
                    buf.field10 = GetAngleDeltaBetween_021a4700((struct Vec3*)((char*)c + 0x44), (short)*(int*)((char*)c + 0x54), (struct Vec3*)((char*)node + 8));
                    func_ov017_0219b33c(obj, &buf);
                    return;
                }
                node = node->next;
            }
        }
    }
}
