#include <globaldefs.h>

struct Obj0205d2bc;
void InitEntries0205d2bc(struct Obj0205d2bc* obj);
extern "C" void func_ov005_0215a620(void* obj);
extern "C" void func_0204b088(void* p, int flag);
struct Entry020e2cc4;
void SetFieldsAt0x4And0x8(int* obj, int a, int b);
extern "C" void func_ov005_0215ae7c(void* obj);
struct Outer020e28dc;
int GetInnerFlagBit0020e28dc(struct Outer020e28dc* o);
void SetEntryEnabled020e2cc4(struct Entry020e2cc4* obj, int enabled);
struct SelfState020e2834;
void SetYesNoButtonPalette020e2834(struct SelfState020e2834* self);
extern "C" void func_ov005_02155d6c(void* obj);

// USA: func_ov005_02155108
ARM void RunTurnStartHooks02155108(void* obj) {
    unsigned char* base = (unsigned char*)obj;

    if (*(unsigned char*)(base + 0x3000 + 0xdc4) != 0xff) return;

    InitEntries0205d2bc((struct Obj0205d2bc*)(base + 0x2e4 + 0xc00));
    func_ov005_0215a620(obj);

    if (*(int*)(base + 0x3000 + 0xdcc) & 0x100) {
        func_0204b088(base + 0x2a4 + 0xc00, 0);
        *(int*)(base + 0x3000 + 0xdcc) &= ~0x100;
    }

    if (*(int*)(base + 0x3000 + 0xdcc) & 0x200) {
        func_ov005_0215ae7c(obj);
        *(int*)(base + 0x3000 + 0xdcc) &= ~0x200;
    }

    if (*(void**)(base + 0xe64) != NULL) {
        unsigned char* r5 = *(unsigned char**)((unsigned char*)(*(void**)(base + 0xe64)) + 0x10);
        int flag;
        SetFieldsAt0x4And0x8((int*)(r5 + 0x28), 0x1f, 1);
        flag = GetInnerFlagBit0020e28dc((struct Outer020e28dc*)*(void**)(base + 0xe64));
        SetEntryEnabled020e2cc4((struct Entry020e2cc4*)(r5 + 0x28), flag);
        SetYesNoButtonPalette020e2834((struct SelfState020e2834*)*(void**)(base + 0xe64));
    }

    func_ov005_02155d6c(obj);
}
