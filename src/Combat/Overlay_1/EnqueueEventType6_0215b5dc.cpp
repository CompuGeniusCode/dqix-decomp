#include <globaldefs.h>

extern "C" void func_ov001_0215b074(int type, int a, int b);

// USA: func_ov001_0215b5dc
ARM int EnqueueEventType6_0215b5dc(int a, int b) {
    func_ov001_0215b074(6, a, b);
    return 1;
}
