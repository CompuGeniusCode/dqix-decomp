#include <globaldefs.h>

int TailInvoke020c6ea4WithExMemCntEntry(int);
extern "C" void func_020cfd7c(int, int);

// USA: func_020d0024
ARM void PrepareAndCommit020d0024(int a) {
    TailInvoke020c6ea4WithExMemCntEntry(a);
    func_020cfd7c(a, 1);
}
