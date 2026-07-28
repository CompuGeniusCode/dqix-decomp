#include <globaldefs.h>

extern "C" double func_0200911c(double val, int* err);
extern "C" double func_020091d8(double val, int err);

// USA: func_0200aae4  (semantic: SomeCombine0200aae4)
extern "C" ARM double func_0200aae4(double val, int c) {
    int err;
    double t = func_0200911c(val, &err);
    err = err + c;
    return func_020091d8(t, err);
}
