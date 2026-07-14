#include <globaldefs.h>

void* GetGlobalManager0209dccc();
extern "C" int func_ov017_021d60f4(void*);

struct Struct0209fde8;
void SetFields0209fde8(struct Struct0209fde8* p, int a, int b, int c);

// USA: func_0209daa4
ARM int SendManagerFields0209daa4(void* self) {
    void* mgr = GetGlobalManager0209dccc();
    if (mgr == NULL) return 0;
    int a = func_ov017_021d60f4(self);
    int b = func_ov017_021d60f4((char*)self + 0x8);
    int c = func_ov017_021d60f4((char*)self + 0x10);
    SetFields0209fde8((struct Struct0209fde8*)mgr, a, b, c);
    return 1;
}
