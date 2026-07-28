#include <globaldefs.h>

#pragma optimize_for_size off

extern "C" THUMB void func_ov031_0221fa58(int a, int b);

// USA: func_ov031_0221fa88  (semantic: CallWithZero_0221fa88)
extern "C" THUMB void func_ov031_0221fa88(int a) {
    func_ov031_0221fa58(a, 0);
}
