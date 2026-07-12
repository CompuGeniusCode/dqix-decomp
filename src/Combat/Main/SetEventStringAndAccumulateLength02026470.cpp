#include <globaldefs.h>
#include "std_library_functions.h"

int CallFunc020e0434With02153694(int value);
extern "C" void func_02003ce8(void*, void*, int, int);
extern "C" int func_020420e8(char*, int);

extern char data_020ef6b5;
extern char data_020ef6c5;

// USA: func_02026470
ARM void SetEventStringAndAccumulateLength02026470(void* obj, int flag) {
    if (flag == 0) {
        strcpy((char*)obj + 0x1f4 + 0x400, &data_020ef6b5);
    } else {
        int v = CallFunc020e0434With02153694(0x3f3);
        func_02003ce8((char*)obj + 0x1f4 + 0x400, &data_020ef6c5, v, flag);
    }
    int len = func_020420e8((char*)obj + 0x1f4 + 0x400, 0);
    *(int*)((char*)obj + 0xbe4) += len + 4;
}
