#include <globaldefs.h>

extern void* data_ov017_021d83ac;
extern "C" void func_ov002_02155f4c(void);

// USA: func_ov017_021a5954
ARM void CallIfGlobalPtrSet_021a5954(void) {
    if (data_ov017_021d83ac == NULL) {
        return;
    }
    func_ov002_02155f4c();
}
