#include <globaldefs.h>

struct Cont0207fd88;
void CallFunc0204b088OverList0x2c(struct Cont0207fd88* obj);
void ClearBitndCleanup_0216720c_0216720c(char* obj);
extern "C" void func_ov003_0216757c(char* obj);
void SetFieldsAt0x4And0x8(int* obj, int a, int b);
struct Outer020e28dc;
int GetInnerFlagBit0020e28dc(struct Outer020e28dc* o);
struct Entry020e2cc4;
void SetEntryEnabled020e2cc4(struct Entry020e2cc4* obj, int enabled);
struct SelfState020e2834;
void SetYesNoButtonPalette020e2834(struct SelfState020e2834* self);

// USA: func_ov003_02160240  (semantic: UpdateEntryAndPalette_02160240)
extern "C" ARM void func_ov003_02160240(char* obj) {
    if (*(unsigned char*)(obj + 0x4a3) == 0) return;
    if (*(struct Cont0207fd88**)(obj + 0x324) != 0) {
        CallFunc0204b088OverList0x2c(*(struct Cont0207fd88**)(obj + 0x324));
    }
    ClearBitndCleanup_0216720c_0216720c(obj);
    if (*(char**)(obj + 0x318) != 0) {
        func_ov003_0216757c(*(char**)(obj + 0x318));
    }
    if (*(void**)(obj + 0x390) == 0) return;
    unsigned char* r4 = *(unsigned char**)((char*)(*(void**)(obj + 0x390)) + 0x10);
    int flag;
    SetFieldsAt0x4And0x8((int*)(r4 + 0x28), 0x19, 1);
    flag = GetInnerFlagBit0020e28dc((struct Outer020e28dc*)*(void**)(obj + 0x390));
    SetEntryEnabled020e2cc4((struct Entry020e2cc4*)(r4 + 0x28), flag);
    SetYesNoButtonPalette020e2834((struct SelfState020e2834*)*(void**)(obj + 0x390));
}
