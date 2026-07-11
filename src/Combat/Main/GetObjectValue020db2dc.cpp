#include <globaldefs.h>

extern "C" int func_0203bd08(int a);
extern "C" int func_0203be4c(int obj);
extern "C" int func_0203be40(int obj);

// USA: func_020db2dc
ARM int GetObjectValue020db2dc(int a, int b) {
    int obj = func_0203bd08(a);
    int v = func_0203be4c(obj);
    if (b != 0) return v;
    return func_0203be40(obj);
}
