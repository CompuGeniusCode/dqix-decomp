#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
void* GetGlobalManager0209dccc();

struct Manager0209d744 {
    unsigned char pad[0x6c];
    int value; // 0x6c
};

// USA: func_0209d744
ARM int StoreValueInManager0209d744(void* arg) {
    struct Manager0209d744* mgr = (struct Manager0209d744*)GetGlobalManager0209dccc();
    if (mgr == NULL) return 0;
    mgr->value = func_ov017_021d60f4(arg);
    return 1;
}
