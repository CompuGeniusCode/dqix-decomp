#include <globaldefs.h>

extern "C" int FastIntDivide(int numer, unsigned int denom);
extern "C" void CallVTableField14_0223ca40(void* obj, int unused);
void SetFlagIfMatchesElem0_0223caec(void* ptr);
extern "C" void func_ov031_0222c45c(int, int);
extern "C" void func_ov031_0222c5d4(int, int);
extern "C" void func_ov031_0222c660(void);

struct Inner0222c3b4 {
    unsigned char pad[0xc];
    void* field0xc;
    unsigned char pad2[0x51 - 0x10];
    unsigned char field0x51;
};
struct Struct0222c3b4 {
    unsigned char pad[2];
    unsigned short field2;
    Inner0222c3b4* field4;
};
extern Struct0222c3b4 data_ov031_02290c8c;

// USA: func_ov031_0222c3b4
#pragma optimize_for_size off
extern "C" ARM void func_ov031_0222c3b4(void) {
    int count = FastIntDivide(data_ov031_02290c8c.field2, 0x1c);
    int n = data_ov031_02290c8c.field4->field0x51;
    CallVTableField14_0223ca40(data_ov031_02290c8c.field4->field0xc, 0);
    if (n > 5) n = 5;

    int a = count;
    int i = 0;
    if (n > 0) {
        do {
            func_ov031_0222c45c(a, i);
            i++;
            a++;
        } while (i < n);
    }
    int b = count;
    int j = 0;
    if (n > 0) {
        do {
            func_ov031_0222c5d4(b, j);
            j++;
            b++;
        } while (j < n);
    }

    SetFlagIfMatchesElem0_0223caec(data_ov031_02290c8c.field4->field0xc);
    func_ov031_0222c660();
}
