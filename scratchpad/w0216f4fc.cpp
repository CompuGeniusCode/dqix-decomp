#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

extern "C" int func_ov004_0216ea38(void* a, int key);
int GetGlobalField0x1c020421a0(void);

extern "C" void* func_ov011_021849c8(void* obj);
extern "C" void* func_ov023_021f6880(void* obj, int key);
int ScaleStatsIfType12_021f6f10(void* self);
extern "C" void func_ov023_021f809c(void* obj, void* param2);

int VariadicForward020c7170(int a, int b, int c, ...);
extern char data_ov004_021707b0;

struct Struct02171048_0216f4fc { char pad[0x4]; char* ptr; };
extern Struct02171048_0216f4fc data_ov004_02171048;

struct NodeField20_0216f4fc { char pad[0x20]; void* field20; };

// USA: func_ov004_0216f4fc
ARM int FormatAndStoreCodeIfType8_0216f4fc(void* obj) {
    void* battle = GetBattleStruct();
    func_ov004_0216ea38(obj, 4);
    GetGlobalField0x1c020421a0();

    NodeField20_0216f4fc* n = (NodeField20_0216f4fc*)func_ov023_021f6880(func_ov011_021849c8(obj), 0x65);
    if (!n || ScaleStatsIfType12_021f6f10(n) != 8) {
        n = 0;
    }

    if (n) {
        char* q = (char*)battle + 0x2380 + 0x4000;
        char buf[13];
        VariadicForward020c7170((int)buf, 13, (int)&data_ov004_021707b0, *(int*)(q + 0x48), *(int*)(q + 0x4c));

        char* src = buf;
        char* dst = data_ov004_02171048.ptr + 0xe;
        for (int i = 0; i < 3; i++) {
            memcpy(dst, src, 4);
            dst += 4;
            src += 4;
            if (i != 2) {
                *dst = 0x2d;
                dst++;
            }
        }
        n->field20 = data_ov004_02171048.ptr + 0xe;
    }

    void* node2 = func_ov023_021f6880(func_ov011_021849c8(obj), 0x14);
    if (!node2 || ScaleStatsIfType12_021f6f10(node2) != 6) {
        node2 = 0;
    }
    if (node2) {
        func_ov023_021f809c(node2, obj);
    }
    return 0;
}
