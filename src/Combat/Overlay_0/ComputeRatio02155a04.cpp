#include <globaldefs.h>

struct RatioFields02155a04 { unsigned short a; unsigned short pad2; unsigned short b; };

// USA: func_ov000_02155a04  (semantic: ComputeRatio02155a04)
extern "C" ARM float func_ov000_02155a04(char* obj) {
    struct RatioFields02155a04* r = *(struct RatioFields02155a04**)(obj + 0x138);
    if ((float)r->a == 0.0f) return 0.0f;
    return (float)r->a / (float)r->b;
}
