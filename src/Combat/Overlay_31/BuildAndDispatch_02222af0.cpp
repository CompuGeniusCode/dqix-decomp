#include <globaldefs.h>

#pragma optimize_for_size off

typedef void (*Callback02222af0)(void*);

struct Table02222af0 {
    int pad[31];
    Callback02222af0 handler;
};

struct Context02222af0 {
    int a;
    int b;
    int c;
};

extern Table02222af0 data_ov031_0224f670;
extern "C" THUMB void func_ov031_02222aa4(Context02222af0* ctx);

// USA: func_ov031_02222af0  (semantic: BuildAndDispatch_02222af0)
extern "C" THUMB void func_ov031_02222af0(void) {
    Context02222af0 ctx;
    func_ov031_02222aa4(&ctx);
    data_ov031_0224f670.handler(&ctx);
}
