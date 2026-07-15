#include <globaldefs.h>

struct FlagObj_021da9b0;
int IsFlagBit8Set_021da9b0(struct FlagObj_021da9b0* obj);

struct Obj_021fd428 {
    char unk[0x661];
    unsigned char flag661;
    char unk2[0x668 - 0x661 - 1];
    struct FlagObj_021da9b0* ptr668;
};

extern "C" void func_ov024_021fd160(void* obj, int mode);

// USA: func_ov024_021fd428
ARM void TrySetSlotFlagAndApply3_021fd428(struct Obj_021fd428* obj) {
    if (IsFlagBit8Set_021da9b0(obj->ptr668)) {
        if (!obj->flag661) {
            func_ov024_021fd160(obj, 3);
        }
    }
}
