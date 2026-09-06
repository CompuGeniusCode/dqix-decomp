#include <globaldefs.h>

void InitSessionFields_0220321c(void);
void ResetSessionState02203190(void);
void ZeroField164_02203250(void);
void UpdateObjFromContext_022031bc(int a, unsigned short b, unsigned int c);
extern "C" int func_ov031_022048a8(void* obj, int flag, void* arg2, int zero1, int zero2);

// USA: func_ov031_02204c20  (semantic: StartSession_02204c20)
#pragma optimize_for_size off
extern "C" ARM int func_ov031_02204c20(void* obj, unsigned int session, void* arg2) {
    if (session == 0) return -1;
    InitSessionFields_0220321c();
    ResetSessionState02203190();
    UpdateObjFromContext_022031bc(0, 0x35, session);
    int result = func_ov031_022048a8(obj, 1, arg2, 0, 0);
    ZeroField164_02203250();
    return result;
}
