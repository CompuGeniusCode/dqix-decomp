#include <globaldefs.h>
void SetIntAt0x8c(struct IntField0x8c_0209fe08*, int);

void* GetGlobalManager0209dccc();
extern "C" int func_ov017_021d60f4(void*);

// USA: func_0209db28
ARM int StoreValueInManager0209db28(void* arg) {
    void* mgr = GetGlobalManager0209dccc();
    if (mgr == NULL) return 0;
    SetIntAt0x8c((struct IntField0x8c_0209fe08*)(mgr), (int)(func_ov017_021d60f4(arg)));
    return 1;
}
