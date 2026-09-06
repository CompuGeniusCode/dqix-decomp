#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_020f0e38[8];
extern float data_02108e40[8];

// USA: func_020e6124
extern "C" __declspec(initcode) ARM void __sinit_020e6124(void) {
    float t;
    float a;
    float b;
    data_02108e40[7] = data_020f0e38[0] + (data_020f0e38[1] + (data_020f0e38[3] + data_020f0e38[2]));
    t = data_02108e40[6] + data_020f0e38[3];
    a = data_020f0e38[2];
    data_02108e40[5] = t;
    t = t + a;
    b = data_020f0e38[1];
    data_02108e40[4] = t;
    t = t + b;
    data_02108e40[3] = t;
}
