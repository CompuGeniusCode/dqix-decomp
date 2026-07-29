#include <globaldefs.h>

struct G3_020ca50c { unsigned int w[3]; };
struct G2_020ca50c { unsigned int w[2]; };
struct Block32_020ca50c { G3_020ca50c a; G3_020ca50c b; G2_020ca50c c; };

// USA: func_020ca50c
ARM void CopyBlock32_020ca50c(Block32_020ca50c* src, Block32_020ca50c* dst) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
}
