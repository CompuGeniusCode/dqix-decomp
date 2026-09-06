#include <globaldefs.h>

struct Vec4F_02164a58 { float x0, x1, x2, x3; };
extern Vec4F_02164a58 data_ov001_02164ba0;

struct Chain_02164a58 { char pad0[8]; float f8, fc, f10, f14, f18; };
extern Chain_02164a58 data_ov001_0216580c;

struct Obj021d49d0;
Obj021d49d0* SetupObj_021d49d0(Obj021d49d0* obj);
extern Obj021d49d0 data_ov001_02165828;

// USA: func_ov001_02164a58
ARM void UpdateFilterChain_02164a58(void) {
    float t1 = data_ov001_02164ba0.x0 + data_ov001_02164ba0.x3;
    float t2 = data_ov001_02164ba0.x2 + t1;
    float t3 = data_ov001_02164ba0.x1 + t2;
    data_ov001_0216580c.f18 = t3;
    float t4 = data_ov001_0216580c.f14 + data_ov001_02164ba0.x0;
    float x3 = data_ov001_02164ba0.x3;
    data_ov001_0216580c.f10 = t4;
    float t5 = t4 + x3;
    float x2 = data_ov001_02164ba0.x2;
    data_ov001_0216580c.fc = t5;
    float t6 = t5 + x2;
    data_ov001_0216580c.f8 = t6;
    SetupObj_021d49d0(&data_ov001_02165828);
}
