#include <globaldefs.h>
#pragma define_section initcode ".init" RX

struct Vec4f020f1a8c { float field0, field4, field8, fieldc; };
struct Accum02109db8 { float field0, field4, field8, fieldc, field10; };

extern struct Vec4f020f1a8c data_020f1a8c;
extern struct Accum02109db8 data_02109db8;

// USA: func_020e64fc
extern "C" __declspec(initcode) ARM void func_020e64fc(void) {
    data_02109db8.fieldc = data_020f1a8c.field0 + (data_020f1a8c.field4 + (data_020f1a8c.fieldc + data_020f1a8c.field8));
    float t = data_02109db8.field8 + data_020f1a8c.fieldc;
    float next8 = data_020f1a8c.field8;
    data_02109db8.field4 = t;
    t = t + next8;
    float next4 = data_020f1a8c.field4;
    data_02109db8.field0 = t;
    t = t + next4;
    data_02109db8.field10 = t;
}
