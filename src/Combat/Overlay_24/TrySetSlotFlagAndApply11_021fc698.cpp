#include <globaldefs.h>

struct S_field113_021fc698 { char unk[0x71]; unsigned char flag; };

extern "C" int func_ov024_021fe698(void* obj, int idx);
extern "C" void func_ov024_021fd954(void* obj, int mode);

// USA: func_ov024_021fc698
ARM void TrySetSlotFlagAndApply11_021fc698(struct S_field113_021fc698* obj) {
    if (obj->flag) {
        if (func_ov024_021fe698(obj, 12)) {
            func_ov024_021fd954(obj, 11);
        }
    }
}
