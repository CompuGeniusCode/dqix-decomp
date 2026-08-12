#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetField0x3b4Value(struct BattleStruct* battleStruct);

struct Mid021eedb0 { unsigned int v[4]; };

struct Rec021eedb0 {
    unsigned int f0;
    unsigned int f4;
    struct Mid021eedb0 mid;
    struct Rec021eedb0* next;
};

struct Obj021eedb0 {
    char pad0[0xe0];
    struct Rec021eedb0* activeHead;
    struct Rec021eedb0* freeHead;
};

typedef int (*Handler021eedb0)(struct Rec021eedb0*);
extern Handler021eedb0 data_ov025_021ef93c[];

// USA: func_ov025_021eedb0
extern "C" ARM void func_ov025_021eedb0(struct Obj021eedb0* obj) {
    struct BattleStruct* battle = GetBattleStruct();
    unsigned int elapsed = GetField0x3b4Value(battle);
    struct Rec021eedb0* node = obj->activeHead;
    struct Rec021eedb0* prev = 0;
    while (node != 0) {
        if (elapsed < node->f4) {
            node->f4 -= elapsed;
        } else {
            node->f4 = 0;
            if (data_ov025_021ef93c[node->f0](node) != 0) {
                if (prev != 0) prev->next = node->next;
                else obj->activeHead = node->next;
                struct Rec021eedb0* next = node->next;
                node->next = obj->freeHead;
                obj->freeHead = node;
                node = next;
                continue;
            }
        }
        prev = node;
        node = node->next;
    }
}
