#include <globaldefs.h>

int GetInterruptSafeQueueField(void);

extern "C" void func_020bd02c(void);
extern "C" void func_020d1f0c(int a, int b, int c, int d);
extern "C" void func_020d24c4(int a);
extern "C" void func_020d2680(int a);

// USA: func_020bbdd8
ARM void ResetQueueAndNotify(void) {
    func_020bd02c();
    func_020d1f0c(0, 0, 0, 0);
    int v = GetInterruptSafeQueueField();
    func_020d24c4(1);
    func_020d2680(v);
}
