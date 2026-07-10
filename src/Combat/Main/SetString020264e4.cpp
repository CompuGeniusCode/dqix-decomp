#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_02042764(const char*, char*, int);
extern char data_020ef6ca;

// USA: func_020264e4
ARM void SetString020264e4(char* obj, char* name) {
    if (name != NULL && *name != 0) {
        func_02042764(name, obj + 0x6f4, 1);
    } else {
        strcpy(obj + 0x6f4, &data_020ef6ca);
    }
}
