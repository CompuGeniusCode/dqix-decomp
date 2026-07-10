#include <globaldefs.h>

extern "C" int func_020e0434(void* obj, int value);
extern int data_021536ac;

// USA: func_020e51e4
ARM int CallFunc020e0434With021536ac(int value) {
    return func_020e0434(&data_021536ac, value);
}
