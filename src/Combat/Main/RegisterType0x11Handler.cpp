#include <globaldefs.h>

extern "C" void func_020cad18(void);
void SetIndexedFlagBit020cae24(int, int);
void DispatchType0x11InitOnce(int, int);

struct InitGuard020d1118 { int done; void* callback; };
extern InitGuard020d1118 data_02112140;

// USA: func_020d1118
ARM void RegisterType0x11Handler(void) {
    func_020cad18();
    SetIndexedFlagBit020cae24(0xe, (int)DispatchType0x11InitOnce);
    data_02112140.callback = NULL;
}
