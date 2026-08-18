#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float func_ov002_02164d14[8];
extern float data_ov001_02165880[8];

// USA: func_ov001_02164aec  (semantic: AccumulateFloats_02164aec)
extern "C" __declspec(initcode) ARM void func_ov001_02164aec(void) {
    float t;
    float a;
    float b;
    data_ov001_02165880[13] = func_ov002_02164d14[1] + (func_ov002_02164d14[0] + (func_ov002_02164d14[2] + func_ov002_02164d14[3]));
    t = data_ov001_02165880[0] + func_ov002_02164d14[2];
    a = func_ov002_02164d14[3];
    data_ov001_02165880[4] = t;
    t = t + a;
    b = func_ov002_02164d14[0];
    data_ov001_02165880[12] = t;
    t = t + b;
    data_ov001_02165880[11] = t;
}
