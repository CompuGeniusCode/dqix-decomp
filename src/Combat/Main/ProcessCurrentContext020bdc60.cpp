#include <globaldefs.h>
void ProcessQueueUntilValueCommitted020d2680(unsigned int);

int GetInterruptSafeQueueField(void);
extern "C" void func_020d24c4(int);

// USA: func_020bdc60
ARM void ProcessCurrentContext020bdc60() {
    int ctx = GetInterruptSafeQueueField();
    func_020d24c4(1);
    ProcessQueueUntilValueCommitted020d2680((unsigned int)(ctx));
}
