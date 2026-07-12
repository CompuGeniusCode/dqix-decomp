#include <globaldefs.h>

extern "C" void func_020c29ec(int a0, int a1, int a2, int a3, int b0, int b1, int b2, void* outBuf);
void GxLoadMatrix4x4(const void* mtx);

#pragma optimize_for_size off
// USA: func_020c5770
ARM void ComputeAndLoadMatrix020c5770(int a0, int a1, int a2, int a3, int b0, int b1, int b2, int gate, void* outBuf) {
    int localBuf[16];
    void* buf = outBuf ? outBuf : localBuf;
    func_020c29ec(a0, a1, a2, a3, b0, b1, b2, buf);
    if (gate == 0) return;
    *(volatile unsigned int*)0x4000440 = 0;
    GxLoadMatrix4x4(buf);
}
