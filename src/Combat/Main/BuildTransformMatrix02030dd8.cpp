#include <globaldefs.h>

struct MtxFx43_02030dd8 { unsigned int v[12]; };

extern "C" int func_02030c68(void* src);
extern "C" int func_02030c9c(void* src);
extern "C" struct MtxFx43_02030dd8 func_020c19b8(int a, int b);

// USA: func_02030dd8
ARM void BuildTransformMatrix02030dd8(struct MtxFx43_02030dd8* dst, void* src) {
    *dst = func_020c19b8(func_02030c68(src), func_02030c9c(src));
}
