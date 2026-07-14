#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void* p);
unsigned int GetBitsInField4(unsigned int* obj, unsigned int mask);
extern "C" void* func_0207ecac(void* p, int v);

struct Vec3Block020b3850;
void StoreVec3AndClearFlags020b3850(struct Vec3Block020b3850* src);

struct Vec3Block020b3880;
void StoreVec3AndClearFlags020b3880(struct Vec3Block020b3880* src);

extern "C" void func_020c1180(void* p);
extern "C" void func_020ca528(void* a, void* b);
extern int data_0210a0cc;

struct S02037418;
void SetFieldAAndSync02037418(struct S02037418* obj, int val);

struct FlagRegs0208f87c { unsigned char pad[0xfc]; unsigned int flags; };
extern struct FlagRegs0208f87c data_0210a010;

void InvokeHandlerAndClearFlags020b3814(void);

struct Battler02035e1c;
int RunActionIfReady02035e1c(struct Battler02035e1c* a, int b, int c, int d, int e);

// USA: func_0208f87c
ARM void SyncBattleState0208f87c(void* self, int b, int c, int d) {
    void* ov = func_ov017_0218b5b0(self);
    void* r4 = *(void**)((char*)ov + 0x36cc);
    if (GetBitsInField4((unsigned int*)ov, 0x200400) != 0) {
        return;
    }
    if (*(void**)((char*)r4 + 0x8) == 0) {
        return;
    }
    func_0207ecac(*(void**)((char*)r4 + 0x8), b);
    StoreVec3AndClearFlags020b3850((struct Vec3Block020b3850*)self);
    unsigned int vec[3] = { (unsigned int)c, (unsigned int)c, (unsigned int)c };
    StoreVec3AndClearFlags020b3880((struct Vec3Block020b3880*)vec);
    char buf1[0x24];
    func_020c1180(buf1);
    func_020ca528(buf1, &data_0210a0cc);
    data_0210a010.flags &= ~0xa4;
    SetFieldAAndSync02037418((struct S02037418*)r4, d);
    InvokeHandlerAndClearFlags020b3814();
    RunActionIfReady02035e1c((struct Battler02035e1c*)r4, 0, 0, 0, 1);
}
