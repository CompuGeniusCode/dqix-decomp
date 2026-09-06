#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int flag);
ARM int IsField18Zero_02237388(void);
extern void* TailCallElemAtIndex30_0223c7c4(int);
extern "C" void func_ov031_02223440(void);
extern "C" void func_ov031_0223cbbc(int, int);
extern void SetField1014_022274d0(int, int);
void GetFields181c_02227520(int*, int*);
void SetField181c_0222750c(int, int);
void SetField_022274c0_022274c0(int v);
extern "C" void func_ov031_0222ea24(void);
extern "C" void func_ov031_02228024(void);

// USA: func_ov031_02233fac  (semantic: CheckAndInitField18_02233fac)
extern "C" ARM void func_ov031_02233fac(void) {
    if (func_ov031_0223c054(1) != 0) return;
    if (func_ov031_0223c054(0) != 0) return;
    if (IsField18Zero_02237388() == 0) return;
    TailCallElemAtIndex30_0223c7c4(0);
    func_ov031_02223440();
    func_ov031_0223cbbc(1, 1);
    func_ov031_0223cbbc(0, 0x15);
    SetField1014_022274d0(2, 1);
    int local;
    GetFields181c_02227520(0, &local);
    if (local == 0) {
        SetField181c_0222750c(0, 0);
        SetField_022274c0_022274c0((int)func_ov031_0222ea24);
        return;
    }
    SetField_022274c0_022274c0((int)func_ov031_02228024);
}
