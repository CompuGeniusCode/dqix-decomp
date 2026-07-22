#include <globaldefs.h>
#include "System/ProcessorContext.h"
#include "System/Interrupts.h"

struct WrapperParam022069d0 { char pad[4]; void* inner; };

struct Ctx022069d0 {
    char pad[0x64];
    void* field64;
    void* field68;
    char pad2[4];
    short field70;
    char pad3;
    signed char field73;
};

extern "C" void func_ov031_022033e8(void);
ARM void UpdateAndWaitOnContext_02203424(void);
ARM void ZeroField164_02203250(void);
ARM void ClearField164_02203178(void);

struct Struct022051a8;
extern "C" int func_ov031_022051a8(void* a, struct Struct022051a8* b);

struct Node02207108;
ARM void* RemoveFromGlobal0224e22c_02207108(Node02207108* item);

struct Item022070e0;
ARM void PushFrontGlobal0224e230_022070f0(Item022070e0* item);

// USA: func_ov031_022069d0
extern "C" ARM int TeardownContextAndRequeue_022069d0(WrapperParam022069d0* wrap) {
    Ctx022069d0* ctx = (Ctx022069d0*)wrap->inner;
    int kind = ctx->field73;
    int shouldWait = 1;
    if (kind != 0 && kind != 4) shouldWait = 0;
    if (shouldWait) {
        AwaitContextCompletion((ProcessorContext*)((char*)ctx->field68 + 0x20));
        func_ov031_022033e8();
        UpdateAndWaitOnContext_02203424();
        ZeroField164_02203250();
    }
    ClearField164_02203178();
    ctx->field70 &= ~6;
    func_ov031_022051a8(ctx->field73 == 2 ? ctx->field68 : ctx->field64, (struct Struct022051a8*)0);
    int state = DisableIRQInterrupts();
    RemoveFromGlobal0224e22c_02207108((Node02207108*)ctx);
    PushFrontGlobal0224e230_022070f0((Item022070e0*)ctx);
    SetIRQInterruptState(state);
    ctx->field70 |= 0x20;
    return 0;
}
