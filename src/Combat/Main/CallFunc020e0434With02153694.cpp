#include <globaldefs.h>

extern "C" int func_020e0434(void* obj, int value);
extern int data_02153694;

// USA: func_020e51cc
ARM int CallFunc020e0434With02153694(int value) {
    return func_020e0434(&data_02153694, value);
}
