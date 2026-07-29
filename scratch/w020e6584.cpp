#include <globaldefs.h>
#pragma define_section initcode ".init" RX

struct Vec4f020f1b40 { float field0, field4, field8, fieldc; };
struct Accum02109fcc { float field0, field4, field8, fieldc, field10; };

extern struct Vec4f020f1b40 data_020f1b40;
extern struct Accum02109fcc data_02109fcc;

// USA: func_020e6584
extern "C" __declspec(initcode) ARM void func_020e6584(void) {
    data_02109fcc.field10 = data_020f1b40.field4 + (data_020f1b40.field8 + (data_020f1b40.field0 + data_020f1b40.fieldc));
    float t = data_02109fcc.fieldc + data_020f1b40.field0;
    float nextC = data_020f1b40.fieldc;
    data_02109fcc.field8 = t;
    t = t + nextC;
    float next8 = data_020f1b40.field8;
    data_02109fcc.field4 = t;
    t = t + next8;
    data_02109fcc.field0 = t;
}
