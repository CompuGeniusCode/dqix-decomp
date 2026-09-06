#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int arg);
int IsField19ZeroOrNull_02222e54(void);
void* TailCallElemAtIndex30_0223c7c4(int idx);
extern "C" int func_ov031_02223440(void);
extern "C" void func_ov031_0223cbbc(int a, int b);
void GetFields181c_02227520(int* a, int* b);
void SetField1014_022274d0(int a, int b);
void SetField_022274c0_022274c0(int v);
void SetField181c_0222750c(int a, int b);
void SetStoredByte1_02230ef0(unsigned char val);
extern "C" int func_ov031_02232508(void);
extern "C" int func_ov031_0222ea24(void);

// USA: func_ov031_0222e960  (semantic: CheckAndSetFieldsThenDispatch_0222e960)
extern "C" ARM void func_ov031_0222e960(void) {
    if (func_ov031_0223c054(1) != 0) return;
    if (func_ov031_0223c054(0) != 0) return;
    if (IsField19ZeroOrNull_02222e54() == 0) return;

    TailCallElemAtIndex30_0223c7c4(0);
    func_ov031_02223440();
    func_ov031_0223cbbc(1, 1);
    func_ov031_0223cbbc(0, 0x15);

    int buf;
    GetFields181c_02227520(0, &buf);
    if (buf != 0) {
        SetField1014_022274d0(2, 1);
        SetField_022274c0_022274c0((int)func_ov031_02232508);
    } else {
        SetField1014_022274d0(2, 0);
        SetField181c_0222750c(0, 0);
        SetStoredByte1_02230ef0(0);
        SetField_022274c0_022274c0((int)func_ov031_0222ea24);
    }
}
