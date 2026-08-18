#include <globaldefs.h>

extern "C" void func_02035a2c(void* obj, int flag);

struct Obj02184918 { char pad0[0xb10]; signed char b10; char pad1[0xb18 - 0xb11]; unsigned int flags_b18; };

// USA: func_ov008_02184918  (semantic: SyncIfStateAndNotBusy_02184918)
extern "C" ARM void func_ov008_02184918(struct Obj02184918* obj) {
    signed char v = obj->b10;
    if (v == 0 || v == 0xe) return;
    if (obj->flags_b18 & 0x80) return;
    *(volatile unsigned int*)0x04000444 = 0;
    func_02035a2c((char*)obj + 0x790, 0);
    *(volatile unsigned int*)0x04000448 = 1;
}
