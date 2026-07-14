#include <globaldefs.h>

extern "C" void func_020c7cb0(void* obj, void (*callback)(int));
void InvokeAndClearCallback0xb4(int arg);
void RestoreThreadContext(void* ctx);
extern char data_021112e0;

struct Obj020c76d0 {
    unsigned int flags;   /* 0x0 */
    int arg;              /* 0x4 */
};

// USA: func_020c76d0
ARM void ScheduleOrInvokeCallback020c76d0(struct Obj020c76d0* obj, int arg1) {
    if (*(int*)(&data_021112e0 + 0x1c) != 0) {
        func_020c7cb0(obj, InvokeAndClearCallback0xb4);
        obj->arg = arg1;
        obj->flags |= 0x80;
        *(unsigned int*)((char*)obj + 0x64) = 1;
        RestoreThreadContext(obj);
    } else {
        InvokeAndClearCallback0xb4(arg1);
    }
}
