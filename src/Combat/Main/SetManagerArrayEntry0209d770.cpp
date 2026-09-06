#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
void* GetGlobalManager0209dccc();

struct Manager0209d770 {
    unsigned char pad[0x70];
    int entries[1];
};

// USA: func_0209d770
ARM int SetManagerArrayEntry0209d770(void* arg) {
    struct Manager0209d770* mgr = (struct Manager0209d770*)GetGlobalManager0209dccc();
    if (mgr == NULL) return 0;
    int index = func_ov017_021d60f4(arg);
    int value = func_ov017_021d60f4((char*)arg + 8);
    mgr->entries[index] = value;
    return 1;
}
