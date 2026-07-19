#include <globaldefs.h>

extern "C" float data_ov017_021d7cbc[4];
extern "C" float data_ov017_021d845c[6];

// USA: func_ov017_021d7200
ARM void SumFloats021d7200() {
    float t1 = data_ov017_021d7cbc[0] + data_ov017_021d7cbc[3];
    float t2 = data_ov017_021d7cbc[2] + t1;
    float t3 = data_ov017_021d7cbc[1] + t2;
    data_ov017_021d845c[5] = t3;
    float t4 = data_ov017_021d845c[4] + data_ov017_021d7cbc[0];
    data_ov017_021d845c[3] = t4;
    float t5 = t4 + data_ov017_021d7cbc[3];
    data_ov017_021d845c[2] = t5;
    float t6 = t5 + data_ov017_021d7cbc[2];
    data_ov017_021d845c[1] = t6;
}
