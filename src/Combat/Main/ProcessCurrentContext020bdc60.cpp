#include <globaldefs.h>

int GetInterruptSafeQueueField(void);
extern "C" void func_020d24c4(int);
extern "C" void func_020d2680(int);

// USA: func_020bdc60
ARM void ProcessCurrentContext020bdc60() {
    int ctx = GetInterruptSafeQueueField();
    func_020d24c4(1);
    func_020d2680(ctx);
}
