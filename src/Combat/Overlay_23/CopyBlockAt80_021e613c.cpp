#include <globaldefs.h>

struct Block3_021e613c { unsigned int w[3]; };

// USA: func_ov023_021e613c  (semantic: CopyBlockAt80_021e613c)
extern "C" ARM void func_ov023_021e613c(struct Block3_021e613c* dst, char* src) {
    *dst = *(struct Block3_021e613c*)(src + 0x50);
}
