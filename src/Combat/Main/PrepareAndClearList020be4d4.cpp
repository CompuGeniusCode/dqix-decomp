#include <globaldefs.h>
void ClearListEntryIfMatch020be3f4(int, void*, unsigned int);

extern "C" void func_020d2c98(int a);

// USA: func_020be4d4
ARM void PrepareAndClearList020be4d4(int a0, int a1, int a2, int a3) {
    ClearListEntryIfMatch020be3f4((int)(a0), (void*)(a2), (unsigned int)(a3));
    func_020d2c98(a0);
}
