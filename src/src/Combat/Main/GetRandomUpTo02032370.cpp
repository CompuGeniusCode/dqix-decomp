#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" double func_0200b074(int);
extern "C" double func_0200b0f0(double, double);
extern "C" int func_0200af44(double);

// USA: func_02032370
ARM int GetRandomUpTo02032370(int n) {
    int r = rand();
    double dn = func_0200b074(n);
    double dr = func_0200b074(r - 1);
    return func_0200af44(func_0200b0f0(dn, dr / 32767.0));
}
