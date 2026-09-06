#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
void* GetBattleStruct();
int GetWord0x0(int* obj);
void SetBothCounters(void* obj, int value, int frames);
extern "C" int func_ov017_0218b5b0(void);

struct Ctx0215b318 { char pad0[0xa]; unsigned short fieldA; char pad1[0xf6]; unsigned char field102; };

// USA: func_ov001_0215b318
ARM int Func_0215b318(void* self, int mode) {
    int a = func_ov017_021d60f4(self);
    int b = ~0xf;
    if (mode >= 2) {
        b = func_ov017_021d60f4((char*)self + 0x8);
    }
    void* battle = GetBattleStruct();
    void* word = (void*)GetWord0x0((int*)battle);
    if (word != NULL) {
        SetBothCounters(word, b, a);
        Ctx0215b318* ctx = *(Ctx0215b318**)((char*)func_ov017_0218b5b0() + 0x3000 + 0x734);
        if (ctx->fieldA <= 3) {
            ctx->field102 = 1;
        }
    }
    return 1;
}
