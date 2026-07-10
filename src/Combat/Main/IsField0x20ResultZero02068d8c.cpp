#include <globaldefs.h>

extern "C" int func_020680cc(int);

// USA: func_02068d8c
ARM int IsField0x20ResultZero02068d8c(int a, void* obj) {
    int* p = *(int**)((char*)obj + 0x20);
    if (p != NULL) {
        return func_020680cc(*p) == 0;
    }
    return 0;
}
