#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

struct Struct_ov017_44C8;
extern "C" void* func_ov017_0218b5b0(void);
int GetGlobalField0x1c020421a0(void);
void* GetDataPtr02114e04_020d6c00(void);
extern "C" void func_ov017_021b6c78(void);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);
extern "C" void func_ov017_021afb8c(char* self, char* name);
extern "C" void* func_0200f374(void* dst, int count);
extern "C" void func_02042764(char* name, void* buf, int flag);
void SetBitsInField4(unsigned int* obj, unsigned int mask);
extern "C" void func_ov017_0218b5c0(int set, int bit);
void DispatchWithGlobalContext020daf9c(int a, int b, int c, int d);
void ClearFlag658_0219aa5c(unsigned char* obj);
int GetField4328_0218d268(void* obj);
struct ThreeByteStruct;
void ClearThreeBytes(struct ThreeByteStruct* s);
void OrBitsIntoField0(unsigned int* p, unsigned int mask);

// USA: func_ov017_021afcec  (semantic: InitCombatEntryAndDispatch_021afcec)
extern "C" ARM int func_ov017_021afcec(unsigned char* obj) {
    struct BattleStruct* bs = GetBattleStruct();
    struct Struct_ov017_44C8* ov = (struct Struct_ov017_44C8*)func_ov017_0218b5b0();
    unsigned char* g = (unsigned char*)GetGlobalField0x1c020421a0();
    unsigned int* dataPtr = (unsigned int*)GetDataPtr02114e04_020d6c00();

    if (obj[9] == 2) {
        func_ov017_021b6c78();
    }
    if (obj[0x284] != 0) {
        struct CombatantStruct* c = GetCombatantAtField0x397c(bs);
        if (c != NULL) {
            CancelPendingAction020397cc((struct Obj020397cc*)c, 0);
        }
    }
    if (obj[9] != 2) {
        func_ov017_021afb8c((char*)obj, (char*)obj + 0xe);
        char* dst = (char*)ov + 0x435c + obj[0xc] * 0x30;
        char buf[0x30];
        func_0200f374(buf, 0x30);
        func_02042764((char*)obj + 0xe, buf, 1);
        strcpy(dst, buf);
    }
    SetBitsInField4((unsigned int*)ov, 0x40);
    func_ov017_0218b5c0(0, -1);
    DispatchWithGlobalContext020daf9c(1, 1, 0, 1);
    g[0x1000 + 0x9d0] = 1;
    ClearFlag658_0219aa5c((unsigned char*)ov);
    ClearThreeBytes((struct ThreeByteStruct*)GetField4328_0218d268(ov));
    OrBitsIntoField0(dataPtr, 0x40000);
    return 1;
}
