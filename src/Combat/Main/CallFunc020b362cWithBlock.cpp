#include <globaldefs.h>

struct BlockHolder0207eac4;
void* GetBlockPointerFromField5c(struct BlockHolder0207eac4* obj);
extern "C" void func_020b362c(void* block);

// USA: func_0207eae0
ARM void CallFunc020b362cWithBlock(struct BlockHolder0207eac4* obj) {
    void* block = GetBlockPointerFromField5c(obj);
    if (block == NULL) return;
    func_020b362c(block);
}
