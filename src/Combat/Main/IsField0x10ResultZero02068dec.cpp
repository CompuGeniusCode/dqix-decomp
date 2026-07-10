#include <globaldefs.h>

extern "C" int func_020680cc(int);

// USA: func_02068dec
ARM int IsField0x10ResultZero02068dec(int a, void* obj) {
    int* p = *(int**)((char*)obj + 0x10);
    if (p != NULL) {
        return func_020680cc(*p) == 0;
    }
    return 0;
}
