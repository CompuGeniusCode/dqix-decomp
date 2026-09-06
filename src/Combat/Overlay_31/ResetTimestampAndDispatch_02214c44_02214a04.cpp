#include <globaldefs.h>

extern "C" void* func_ov031_022133f8(unsigned int flags);
int GetField9OrZero_022134b0(void);
int GetField260_0220d540(void);
ARM int ResetTimestampAndDispatch_02214c44(char* obj);
extern "C" int func_ov031_0221508c(char* obj, int mode);
extern "C" int func_ov031_02214c94(char* obj);
extern "C" int func_ov031_02214d80(char* obj);
extern "C" int func_ov031_02214ea8(char* obj);

// USA: func_ov031_02214a04  (semantic: DispatchByField9And260_02214a04)
extern "C" ARM int func_ov031_02214a04(void) {
    char* obj = (char*)func_ov031_022133f8(0x10);
    int f9 = GetField9OrZero_022134b0();
    int f260 = GetField260_0220d540();
    int result = f9;
    if (f9 == 2 && f260 == 3) {
        result = ResetTimestampAndDispatch_02214c44(obj);
    } else if (f9 == 6) {
        result = func_ov031_0221508c(obj, f9);
    } else if (f260 == 3 || f260 == 6) {
        result = func_ov031_0221508c(obj, f9);
        if (result != 7) {
            if (result == 3) result = func_ov031_02214c94(obj);
            else if (result == 4) result = func_ov031_02214d80(obj);
            else if (result == 5) result = func_ov031_02214ea8(obj);
        }
    }
    return result;
}
