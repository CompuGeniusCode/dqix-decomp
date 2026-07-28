#include <globaldefs.h>

struct Inner02049fc0 { unsigned char pad[0x64]; float val; };
struct S02049fc0 { unsigned char pad[0x13c]; Inner02049fc0* inner; };

// USA: func_02049fc0  (semantic: CheckFieldNonZero02049fc0)
extern "C" ARM int func_02049fc0(S02049fc0* obj) {
    Inner02049fc0* inner = obj->inner;
    if (inner == 0) {
        return 0;
    }
    return inner->val != 0.0f;
}
