#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_020f0420[8];
extern float data_021079cc[8];

// USA: func_020e5e2c
extern "C" __declspec(initcode) ARM void __sinit_020e5e2c(void) {
    float t;
    float a;
    float b;
    data_021079cc[1] = data_020f0420[3] + (data_020f0420[0] + (data_020f0420[4] + data_020f0420[2]));
    t = data_021079cc[0] + data_020f0420[4];
    a = data_020f0420[2];
    data_021079cc[4] = t;
    t = t + a;
    b = data_020f0420[0];
    data_021079cc[3] = t;
    t = t + b;
    data_021079cc[2] = t;
}
