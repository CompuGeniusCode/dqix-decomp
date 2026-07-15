#include <globaldefs.h>

extern void* data_ov017_021d83ac;
extern "C" void func_ov002_0216bfd4(void);

// USA: func_ov017_021a5a28
ARM void CallIfGlobalPtrSet_021a5a28(void) {
    if (data_ov017_021d83ac == NULL) {
        return;
    }
    func_ov002_0216bfd4();
}
