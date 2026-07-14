#include <globaldefs.h>

int CallFunc020e0434With02153694(int value);
extern "C" void sprintf(void*, void*, int, int);
extern unsigned char data_020f1ac4[];

// USA: func_020a451c
ARM void EmitObjectEvent0x3f3(void* obj) {
    int v = CallFunc020e0434With02153694(0x3f3);
    sprintf((char*)obj + 0xf0, data_020f1ac4, v, *(unsigned char*)((char*)obj + 0xa));
}
