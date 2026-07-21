#include <globaldefs.h>

extern void* data_ov031_0224e580;

extern "C" int func_ov031_022102c8(void);
void SetGlobal0224e588FieldA0c_02210314(int);
void InvokeCallbackField28IfMatch_0220fdec(int, int*);

// USA: func_ov031_0220fe44  (semantic: RegisterCallback28_0220fe44)
extern "C" ARM int func_ov031_0220fe44(int arg) {
    if (data_ov031_0224e580 == NULL) return 0;
    if (!func_ov031_022102c8()) return 0;
    *(int*)((char*)data_ov031_0224e580 + 0x2c) = 0;
    *(int*)((char*)data_ov031_0224e580 + 0x28) = arg;
    SetGlobal0224e588FieldA0c_02210314((int)InvokeCallbackField28IfMatch_0220fdec);
    return 1;
}
