#include <globaldefs.h>

ARM void SetField1e_0223521c(void);
extern "C" void func_ov031_022238cc(void);
int HwDivideRemainder(int, int);
extern "C" void func_ov031_0222c660(void);
extern "C" void func_ov031_0222c3b4(void);
int Divide32(int numer, unsigned int denom);
extern "C" void func_ov031_022351f8(int a);
ARM void ClearField1e_02235204(void);
extern "C" void func_ov031_0222c8cc(void);
extern "C" void func_ov031_0223e2c0(int idx, void* obj);

struct Inner0222c7d8 {
    unsigned char pad0[0x38];
    int field38;
    unsigned char pad1[0x40 - 0x38 - 4];
    unsigned short field40;
    unsigned char pad2[0x53 - 0x42];
    unsigned char field53;
};
struct Struct0222c7d8 {
    unsigned char pad[2];
    unsigned short field2;
    Inner0222c7d8* field4;
};
extern Struct0222c7d8 data_ov031_02290c8c;

// USA: func_ov031_0222c7d8
extern "C" ARM void AdvanceCounterAndDispatch_0222c7d8(void* param0) {
    SetField1e_0223521c();
    func_ov031_022238cc();
    data_ov031_02290c8c.field2 += 4;
    int rem = HwDivideRemainder(data_ov031_02290c8c.field2, 0x1c);
    if (rem >= 4) {
        func_ov031_0222c660();
        return;
    }
    data_ov031_02290c8c.field2 = data_ov031_02290c8c.field2 - rem;
    func_ov031_0222c3b4();
    int mulVal = data_ov031_02290c8c.field2 * data_ov031_02290c8c.field4->field53;
    int divResult = Divide32(mulVal, data_ov031_02290c8c.field4->field40);
    func_ov031_022351f8(divResult);
    ClearField1e_02235204();
    func_ov031_0222c8cc();
    data_ov031_02290c8c.field4->field38 = 0;
    func_ov031_0223e2c0(0, param0);
}
