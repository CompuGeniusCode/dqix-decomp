#include <globaldefs.h>

int GetGlobalField0x1c020421a0(void);
void ShiftInBitOnGlobalObject(void);
void CallFunc02030110OnGlobalObject(void);
int GetData02104304Field4(void);
extern "C" void func_020301c8(int a, int b);

struct Entry_0205d6a0;
void ResetEntryList0205d6a0(struct Entry_0205d6a0* a, int flag);
void ReinitController02043204(char* obj);
extern "C" void func_ov003_0217db88(void* obj);

// USA: func_ov003_0217dc40  (semantic: ReinitEntryListAndController_0217dc40)
extern "C" ARM void func_ov003_0217dc40(char* obj) {
    int g = GetGlobalField0x1c020421a0();
    ShiftInBitOnGlobalObject();
    CallFunc02030110OnGlobalObject();
    int v = *(int*)(obj + 0xc);
    if (v != -1) {
        int gd = GetData02104304Field4();
        func_020301c8(gd, v);
    }
    ResetEntryList0205d6a0(*(struct Entry_0205d6a0**)(obj + 0x90), 0);
    ReinitController02043204((char*)g);
    func_ov003_0217db88(obj);
}
