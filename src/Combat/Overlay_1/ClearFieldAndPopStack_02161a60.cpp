#include <globaldefs.h>

extern "C" char* func_ov017_0218b5b0(void);
extern "C" void func_ov028_021d8c20(int);
void PopStack1AndTrigger(int flag);

// USA: func_ov001_02161a60
ARM int ClearFieldAndPopStack_02161a60(void) {
    char* p = *(char**)(func_ov017_0218b5b0() + 0x3000 + 0x734);
    int v = *(int*)(p + 0x160);
    func_ov028_021d8c20(v);
    *(int*)(p + 0x160) = 0;
    PopStack1AndTrigger(1);
    return 1;
}
