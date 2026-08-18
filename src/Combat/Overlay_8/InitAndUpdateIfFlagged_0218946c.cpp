#include <globaldefs.h>

struct Obj0205d2bc;
void InitEntries0205d2bc(struct Obj0205d2bc*);
extern "C" void func_ov008_02184968(void* p);

struct FlagE99_0218946c { char pad[0x99]; signed char flag99; };
struct FlagE9b_0218946c { char pad[0x9b]; signed char flag9b; };
struct FlagEc0_0218946c { char pad[0xec0]; unsigned char flag : 1; };

// USA: func_ov008_0218946c  (semantic: InitAndUpdateIfFlagged_0218946c)
extern "C" ARM void func_ov008_0218946c(char* obj) {
    if (((struct FlagE99_0218946c*)(obj + 0xe00))->flag99 != 0) {
        InitEntries0205d2bc((struct Obj0205d2bc*)(obj + 0x18));
    }
    if (((struct FlagE9b_0218946c*)(obj + 0xe00))->flag9b == 0) return;
    if (!((struct FlagEc0_0218946c*)obj)->flag) return;
    func_ov008_02184968(obj + 0x2a8);
}
