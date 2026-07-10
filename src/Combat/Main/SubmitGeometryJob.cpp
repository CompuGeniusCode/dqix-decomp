#include <globaldefs.h>

extern "C" void func_020c20d4(int, int, int, void*);
void IssueCommand0x17(int cmd);

// USA: func_020c57d4
#pragma optimize_for_size off
ARM void SubmitGeometryJob(int a, int b, int c, int flag, void* buf) {
    unsigned char local[0x30];
    void* dst = buf ? buf : local;
    func_020c20d4(a, b, c, dst);
    if (!flag) return;
    *(volatile int*)0x4000440 = 2;
    IssueCommand0x17((int)dst);
}
