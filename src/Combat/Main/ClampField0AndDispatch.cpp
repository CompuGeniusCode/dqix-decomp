#include <globaldefs.h>

struct DispatchTarget020b78bc {
    char pad0[4];
    unsigned short field4;
};

struct DispatchArgs020b78bc {
    int field0;
    int pad4;
    struct DispatchTarget020b78bc* field8;
};

extern "C" void func_020b7ba0(struct DispatchTarget020b78bc* target, int a1, int a2, int a3);

// USA: func_020b78bc
ARM void ClampField0AndDispatch(int a0, struct DispatchArgs020b78bc* args, int a2) {
    struct DispatchTarget020b78bc* target = args->field8;
    int value = args->field0;
    int limit = target->field4 << 12;
    if (value >= limit) {
        value = limit - 1;
    } else if (value < 0) {
        value = 0;
    }
    func_020b7ba0(target, a2, value, a0);
}
