#include <globaldefs.h>

struct S02170c7c {
    char pad[8];
    short denom;
    short pad2;
    short numer;
};

// USA: func_ov000_02170c7c  (semantic: ClassifyRatio02170c7c)
extern "C" ARM int func_ov000_02170c7c(struct S02170c7c* obj) {
    int result = 0;
    short denom = obj->denom;
    if (denom == 0) return 6;
    short numer = obj->numer;
    float ratio = (float)numer / (float)denom;
    if (ratio <= 0.0f) {
        result = 6;
    } else if (ratio <= 0.08f) {
        result = 5;
    } else if (ratio <= 0.25f) {
        result = 4;
    }
    return result;
}
