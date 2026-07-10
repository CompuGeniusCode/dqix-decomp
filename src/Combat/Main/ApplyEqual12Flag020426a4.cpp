#include <globaldefs.h>

int IsValueEqual12(int x);
extern "C" int func_02042658(int flag, int value);

// USA: func_020426a4
ARM int ApplyEqual12Flag020426a4(int a, int b) {
    return func_02042658(IsValueEqual12(a), b);
}
