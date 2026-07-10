#include <globaldefs.h>

extern "C" void func_020cfcf8(int, int);
int Invoke020c6e94ClearExMem0x800(int);

// USA: func_020d0008
ARM void InitAndInvoke020d0008(int a) {
    func_020cfcf8(a, 1);
    Invoke020c6e94ClearExMem0x800(a);
}
