#include <globaldefs.h>

void IssueCommand0x19(int cmd);  // func_020c51a4
extern "C" void func_02016e14(void* a, void* b, void* c, int d);

// USA: func_02016db4
ARM void PushMatrixAndRender02016db4(void* obj, void* node) {
    *(int*)0x4000444 = 0;
    if (*(short*)((char*)obj + 0x474) != 0) {
        IssueCommand0x19((int)((char*)obj + 0x444));
    }
    func_02016e14(obj, node, *(void**)((char*)node + 0x44), 0);
    *(int*)0x4000448 = 1;
}
