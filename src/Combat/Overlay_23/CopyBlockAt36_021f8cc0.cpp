#include <globaldefs.h>

struct Block3_021f8cc0 { unsigned int w[3]; };

// USA: func_ov023_021f8cc0  (semantic: CopyBlockAt36_021f8cc0)
extern "C" ARM void func_ov023_021f8cc0(struct Block3_021f8cc0* dst, char* src) {
    *dst = *(struct Block3_021f8cc0*)(src + 0x24);
}
