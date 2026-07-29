#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" double func_0200b074(int);
extern "C" double func_0200b0f0(double, double);
extern "C" int func_0200af44(double);

// USA: func_020323c4  (semantic: GetRandomInRange020323c4)
extern "C" ARM int func_020323c4(int min, int max) {
    int r = rand();
    double dRange = func_0200b074(max + 1 - min);
    double dr = func_0200b074(r - 1);
    return min + func_0200af44(func_0200b0f0(dRange, dr / 32767.0));
}
