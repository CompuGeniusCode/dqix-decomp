#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

extern "C" signed char func_ov004_02157128(void* obj);
struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);
extern "C" void* func_ov004_02156f04(void* a, int key);
extern "C" void* func_ov004_02156f6c(void* a, int key);
extern "C" void func_ov023_021f809c(void* obj, void* param2);

struct Struct021707d8_0215951c { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_0215951c data_ov004_021707d8;
extern unsigned char data_ov004_0216fb10[8];

struct P150Entry_0215951c {
    char pad0[4];
    void* field4;
    unsigned int field8low4 : 4;
    unsigned int field8rest : 28;
    char pad2[0xc];
    short field18;
};

class VObj0215951c {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53();
    virtual void Method54(int arg);
    int pad4[7];
    void* field0x20;
};

// USA: func_ov004_0215951c
extern "C" ARM int func_ov004_0215951c(void* self) {
    signed char id = func_ov004_02157128(self);
    struct CombatantStruct* combatant = GetCombatantWithFlag0x100(GetBattleStruct(), id);
    if (!combatant) return 0;

    data_ov004_021707d8.ptr[0x12] = id;
    unsigned char buf[8];
    unsigned char* s = (unsigned char*)data_ov004_0216fb10;
    unsigned char* d = buf;
    int n = 8;
    do {
        unsigned char v = *s++;
        *d++ = v;
    } while (--n != 0);

    int key = 0x384;
    for (short i = 0; i < 8; i++, key++) {
        unsigned char slotIdx = buf[i];
        int vtableArg = 3;
        void* ptr9 = 0;

        if (slotIdx != 0xff) {
            char* p150 = *(char**)((char*)combatant + 0x150);
            struct P150Entry_0215951c* entry = (struct P150Entry_0215951c*)(p150 + 0x194 + (slotIdx << 5));
            if (entry != 0) {
                if (entry->field18 > 0) {
                    if (entry->field8low4 != 0xb) {
                        ptr9 = entry->field4;
                        if (ptr9 != 0) {
                            signed char b = *(signed char*)ptr9;
                            if (b != 0) {
                                vtableArg = 0xf;
                            } else {
                                ptr9 = 0;
                            }
                        }
                    }
                }
            }
        }

        VObj0215951c* node = (VObj0215951c*)func_ov004_02156f04(self, key);
        if (node) {
            node->field0x20 = ptr9;
            node->Method54(vtableArg);
        }
    }

    void* node2 = func_ov004_02156f6c(self, 0x16);
    if (node2) func_ov023_021f809c(node2, self);

    return 0;
}
