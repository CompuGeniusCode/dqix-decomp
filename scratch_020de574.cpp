#include <globaldefs.h>

struct Ctx020de574 { char pad[0x10]; int field0x10; };
struct State020de574 { char pad[0x4]; int field4; };

// USA: func_020de574
ARM int UpdateCounterField_020de574(Ctx020de574* ctx, State020de574* state) {
    int counter = state->field4;
    int shouldZero = 1;
    int minusOne = shouldZero - 2;
    if (minusOne != counter && ctx->field0x10 != 0) {
        shouldZero = 0;
    }
    int result;
    if (shouldZero) {
        result = 0;
    } else {
        result = ctx->field0x10 + counter;
    }
    state->field4 = result;
    return 1;
}
