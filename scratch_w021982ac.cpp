#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
void* GetPointerFromArray0x3c(unsigned char* obj, unsigned int index);
int GetFieldIfFlag4(char* obj);
int CheckField0x245Bit0x2Set(unsigned char* obj);
void SetOrClearField0x245Bit0x2(unsigned char* obj, int flag);
struct Struct020a2928;
void CopySubstateAndSetFlag4_020a2908(unsigned char* obj, struct Struct020a2928* src);
void CopySubstateAndSetFlag4_020a296c(unsigned char* obj, struct Struct020a2928* src);
void BlankFunction020a28dc(void);
void ClearFlagAt0x240(unsigned char* obj);
void SetFlagAt0x240(unsigned char* obj);
struct S_a28e0;
void ResetField270Block(struct S_a28e0* p);
void ClearFlag0x4At0x245(unsigned char* obj);

extern "C" void* func_02012fe4(void);
extern "C" int func_02094b9c(void* node, void* buf);

struct Buf3_021982ac { unsigned int w[3]; };

struct ListNode_021982ac {
    char pad_00[0x2c];
    unsigned char value:7;
    unsigned char flagBit:1;
};

// USA: func_ov017_021982ac
ARM void ProcessMatchedListNode_021982ac(void) {
    struct BattleStruct* battle = GetBattleStruct();
    unsigned char* base = (unsigned char*)func_02012fe4();
    struct CombatantStruct* combatant = GetCombatantAtField0x397c(battle);
    Buf3_021982ac localBuf = *(Buf3_021982ac*)((unsigned char*)combatant + 0x44);
    struct ListNode_021982ac* node = (struct ListNode_021982ac*)GetPointerFromArray0x3c(base + 0x6c, 4);
    unsigned char* fieldPtr = (unsigned char*)GetFieldIfFlag4((char*)battle);
    int handled = 0;
    if (fieldPtr != 0) {
        while (node != 0) {
            if (func_02094b9c(node, &localBuf) != 0) {
                if (node->value == 4) {
                    if (CheckField0x245Bit0x2Set(fieldPtr) != 0) {
                        SetOrClearField0x245Bit0x2(fieldPtr, 0);
                    }
                    CopySubstateAndSetFlag4_020a2908(fieldPtr, (struct Struct020a2928*)((char*)node + 0x30));
                    handled = 1;
                } else if (node->value == 5) {
                    CopySubstateAndSetFlag4_020a296c(fieldPtr, (struct Struct020a2928*)((char*)node + 0x30));
                    handled = 1;
                } else {
                    struct Struct020a2928* a = (struct Struct020a2928*)((char*)node + 0x30);
                    struct Struct020a2928* b = (struct Struct020a2928*)((char*)node + 0x5c);
                    (void)a; (void)b;
                    BlankFunction020a28dc();
                }
                if (!node->flagBit) {
                    ClearFlagAt0x240(fieldPtr);
                }
                break;
            }
            node = *(struct ListNode_021982ac**)((char*)node + 0x70);
        }
        if (node == 0) {
            SetFlagAt0x240(fieldPtr);
            ResetField270Block((struct S_a28e0*)fieldPtr);
        }
        if (!handled) {
            ClearFlag0x4At0x245(fieldPtr);
        }
    }
}
