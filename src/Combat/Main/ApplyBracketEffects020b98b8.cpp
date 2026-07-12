#include <globaldefs.h>

struct Ctx020b98b8 {
    unsigned int field0;
    char pad4[4];
    void* field8;
    char padC[8];
    void* field14;
};

struct EntryBytes020b98b8 { unsigned short key; unsigned char b2; unsigned char b3; };

struct List_b780c;
void* FindBracketEntry020b7798(struct List_b780c* obj, unsigned int index, unsigned int target);

struct List020b7740;
void* GetElement020b7740(struct List020b7740* list, unsigned int index);

struct List020b776c;
void* GetElement020b776c(struct List020b776c* list, unsigned int index);

extern "C" void func_020b9778(void* a, void* b, int c);
extern "C" void func_020b9850(void* a, void* b, int c);

// USA: func_020b98b8
ARM void ApplyBracketEffects020b98b8(int handle, struct Ctx020b98b8* ctx, unsigned int val) {
    void* obj = ctx->field8;
    struct EntryBytes020b98b8* e = (struct EntryBytes020b98b8*)FindBracketEntry020b7798(
        (struct List_b780c*)obj, (unsigned short)val, (ctx->field0 >> 12) & 0xffff);
    void* elem1 = GetElement020b7740((struct List020b7740*)obj, e->b2);
    func_020b9778(ctx->field14, elem1, handle);
    if (e->b3 == 0xff) return;
    void* elem2 = GetElement020b776c((struct List020b776c*)obj, e->b3);
    func_020b9850(ctx->field14, elem2, handle);
}
