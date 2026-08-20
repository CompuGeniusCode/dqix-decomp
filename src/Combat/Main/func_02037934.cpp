#include <globaldefs.h>

struct S02037484;
struct S02037418;
struct S_37760;

extern "C" int _Z22MulFieldsDiv3102037484P9S02037484(struct S02037484* obj);
extern "C" void _Z24SetFieldAAndSync02037418P9S02037418i(struct S02037418* obj, int val);
struct S_37760* GetSelfIfField0xa8Bit0Set(struct S_37760* obj);
extern "C" int _Z26GetBitsAndDispatch020b6c3cPvS_S_j(void* a0, void* a1, void* a2, unsigned int a3);
extern "C" void func_0203574c(void* ctx);
extern "C" void func_02035a2c(void* obj, int flag);

struct Node02037934 {
    char pad0[0x40];
    unsigned char lo40 : 3;
    unsigned char a : 5;
    unsigned char b : 5;
    unsigned char hi41 : 3;
    char pad1[0x2a];
    unsigned int field_6c;
    char pad2[0x22];
    short field_92;
    char pad3[0x4];
    struct Node02037934* sub;
};

struct Ctx02037934 {
    char pad0[0x8];
    struct S_37760* field_8;
};

// USA: func_02037934
extern "C" ARM void func_02037934(struct Node02037934* obj, struct Ctx02037934* ctx) {
    char bufA[0x30];
    char bufB[0x24];
    struct S_37760* target;
    unsigned short saved;
    unsigned char scaled;
    int handled;

    if (obj->sub == NULL) return;

    if (obj->sub->field_92 < 0) {
        func_02037934(obj->sub, ctx);
        func_0203574c(ctx);
        scaled = _Z22MulFieldsDiv3102037484P9S02037484((struct S02037484*)obj);
        _Z24SetFieldAAndSync02037418P9S02037418i((struct S02037418*)obj->sub, scaled);
        func_02035a2c(obj->sub, 0);
        return;
    }

    handled = 0;
    if (ctx->field_8 != NULL) {
        target = GetSelfIfField0xa8Bit0Set(ctx->field_8);
        if (target != NULL) {
            if (_Z26GetBitsAndDispatch020b6c3cPvS_S_j(target, bufA, bufB, obj->sub->field_92)) {
                saved = obj->sub->field_6c;
                obj->sub->field_6c |= 0x4800;
                _Z24SetFieldAAndSync02037418P9S02037418i((struct S02037418*)obj->sub,
                    (unsigned char)(obj->a * obj->b / 31));
                func_02035a2c(obj->sub, 1);
                obj->sub->field_6c = saved;
                func_02037934(obj->sub, ctx);
                handled = 1;
            }
        }
    }

    if (handled == 0) {
        func_02037934(obj->sub, ctx);
    }
}
