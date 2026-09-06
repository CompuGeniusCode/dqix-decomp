#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int flag);
void SetElemField38_0223e330(int idx, unsigned char val);
void ClearSlot_0223bd88(int idx);
int FreeStoredPtr_02223984(void);
int FreeArrayAndPtr0_02223708(void);
void ForwardField8AndDeref60_02227688(void* a);
void TailCallRelease_0222761c(void);
int TailCallPtrToGlobal_02235c5c(void);
void SetField1Const_0222758c(void);
extern void* data_ov031_02290c4c;

// USA: func_ov031_02227d20  (semantic: ResetSlotsAndTailCall_02227d20)
extern "C" ARM void func_ov031_02227d20(void) {
    if (func_ov031_0223c054(1)) return;
    if (func_ov031_0223c054(0)) return;
    SetElemField38_0223e330(0, 0);
    SetElemField38_0223e330(1, 0);
    ClearSlot_0223bd88(1);
    ClearSlot_0223bd88(0);
    FreeStoredPtr_02223984();
    FreeArrayAndPtr0_02223708();
    ForwardField8AndDeref60_02227688(data_ov031_02290c4c);
    TailCallRelease_0222761c();
    TailCallPtrToGlobal_02235c5c();
    SetField1Const_0222758c();
}
