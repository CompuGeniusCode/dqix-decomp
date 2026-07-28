#include <globaldefs.h>

struct BlockHolder0207eac4;
void* GetBlockPointerFromField5c(struct BlockHolder0207eac4* obj);
extern "C" void func_020b357c(void* block, int value);

struct FlagHolder0207ea8c { char pad[0xa8]; int flag : 1; };
struct Field58Holder0207ea8c { char pad[0x58]; int field0x58; };

// USA: func_0207ea8c  (semantic: CallFunc020b357cIfFlagAndField58)
extern "C" ARM void func_0207ea8c(FlagHolder0207ea8c* obj, Field58Holder0207ea8c* p) {
    if (obj->flag && p != 0) {
        void* block = GetBlockPointerFromField5c((struct BlockHolder0207eac4*)obj);
        int v = p->field0x58;
        if (block != 0 && v != 0) {
            func_020b357c(block, v);
        }
    }
}
