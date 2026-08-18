#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct BattleStruct;
BattleStruct* GetBattleStruct();
extern "C" int func_ov017_0218b5b0(void);
extern "C" int func_ov017_02195658(void);
void* GetData02108ea8(void);
extern "C" void func_ov000_02174a50(void* obj, int combatantId);
void ClearBitAt0x34(unsigned char* obj, int index);

struct Entry0207da94;
void ProcessEntries0207da94(struct Entry0207da94* list, int idx);

int TestBitAt0x34(unsigned char* obj, unsigned int index);

extern "C" int func_ov017_021959b4(void);
void SetCombatWorkFlags0x55f4(void* work, int mask);

void ResetAndReinit_021f52c8(void* obj);
void InitCombatEntry_021d8b6c(void* obj);
extern "C" void func_ov023_021d8af8(void* obj);
extern "C" void func_ov023_021d8bb4(void* obj);

struct Pair021ed9f8 { unsigned int a; unsigned int b; };
extern struct Pair021ed9f8 data_020e6d5c;

struct DispatchEntry021ed9f8 { unsigned int fn; unsigned int locator; };
extern struct DispatchEntry021ed9f8 data_ov023_021fe148[];

struct Global021ffefc {
    void* inner;
    char pad4[4];
    unsigned int flags;
};
extern struct Global021ffefc data_ov023_021ffefc;

struct InnerReset021ed9f8 {
    char pad0[4];
    int f4;
    int f8;
    int fc;
};

// USA: func_ov023_021ed9f8  (semantic: ScaleOrResetCombatants_021ed9f8)
extern "C" ARM void func_ov023_021ed9f8(char* obj) {
    GetBattleStruct();
    int dataX = (int)BackgroundLoader::GetInstance();
    func_ov017_0218b5b0();
    unsigned char* p = *(unsigned char**)(obj + 0x2a0);
    int n = func_ov017_02195658();
    if (n > 0) {
        void* q = GetData02108ea8();
        func_ov000_02174a50(obj + 0x3760, n);
        ClearBitAt0x34(p, n & 0xff);
        ProcessEntries0207da94((struct Entry0207da94*)q, (int)(unsigned char)n);
        if (n == (signed char)p[0x2a]) {
            for (int i = 0; i < 4; i++) {
                if (TestBitAt0x34(p, i & 0xff)) {
                    p[0x2a] = i;
                    break;
                }
            }
        }
    }

    unsigned int flags = data_ov023_021ffefc.flags;
    if (!(flags & 1)) {
        unsigned int va = *(volatile unsigned int*)&data_020e6d5c.a;
        unsigned int vb = *(volatile unsigned int*)&data_020e6d5c.b;
        *(unsigned int*)((char*)data_ov023_021fe148 + 0x88) = va;
        *(unsigned int*)((char*)data_ov023_021fe148 + 0x8c) = vb;
        data_ov023_021ffefc.flags = flags | 1;
    }

    int idx = *(int*)(obj + 0xeac);
    struct DispatchEntry021ed9f8* d = &data_ov023_021fe148[idx];
    void* base = obj + ((int)d->locator >> 1);
    void* callback;
    if (d->locator & 1) {
        callback = *(void**)((char*)*(void**)base + d->fn);
    } else {
        callback = (void*)d->fn;
    }
    int result = ((int(*)(void*))callback)(base);
    *(int*)(obj + 0xeac) = result;

    int reinit = 0;
    if (func_ov017_021959b4()) {
        if (*(unsigned char*)(obj + 0x77d1) == 0) {
            SetCombatWorkFlags0x55f4(obj, 0x2000000);
            reinit = 1;
        }
    }

    if (reinit) {
        ResetAndReinit_021f52c8((char*)data_ov023_021ffefc.inner + 0xf4);
        if (*(void**)(obj + 0x5588) != NULL) {
            InitCombatEntry_021d8b6c(*(void**)(obj + 0x5588));
            func_ov023_021d8af8(*(void**)(obj + 0x5588));
            *(void**)(obj + 0x5588) = NULL;
        }

        if (((InnerReset021ed9f8*)data_ov023_021ffefc.inner)->f4 > -1) {
            ((BackgroundLoader*)(dataX))->RemoveTask((int)(((InnerReset021ed9f8*)data_ov023_021ffefc.inner)->f4));
        }
        if (((InnerReset021ed9f8*)data_ov023_021ffefc.inner)->f8 > -1) {
            ((BackgroundLoader*)(dataX))->RemoveTask((int)(((InnerReset021ed9f8*)data_ov023_021ffefc.inner)->f8));
        }
        if (((InnerReset021ed9f8*)data_ov023_021ffefc.inner)->fc > -1) {
            ((BackgroundLoader*)(dataX))->RemoveTask((int)(((InnerReset021ed9f8*)data_ov023_021ffefc.inner)->fc));
        }

        ((InnerReset021ed9f8*)data_ov023_021ffefc.inner)->f4 = -1;
        ((InnerReset021ed9f8*)data_ov023_021ffefc.inner)->f8 = -1;
        ((InnerReset021ed9f8*)data_ov023_021ffefc.inner)->fc = -1;
        return;
    }

    void* entry = *(void**)(obj + 0x5588);
    if (entry == NULL) return;
    func_ov023_021d8bb4(entry);
}
