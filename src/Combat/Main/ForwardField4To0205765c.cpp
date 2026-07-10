#include <globaldefs.h>

extern "C" int func_0205765c(int);

// USA: func_0205578c
ARM int ForwardField4To0205765c(int* obj) {
    int x = obj[1];
    if (x == 0) return x;
    return func_0205765c(x);
}
