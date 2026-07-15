#include <globaldefs.h>
#include "std_library_functions.h"

int GetGlobalField0x1c020421a0();
extern "C" void func_ov000_02176500(void* obj, void* buf, int flag);

struct StructA0205d5d0;
int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);

// USA: func_ov000_02176498
ARM void RunElemFieldsIfField_02176498_02176498(void* obj, int flag) {
    if (*(void**)((char*)obj + 0x38) != 0) {
        void* buf = *(void**)(GetGlobalField0x1c020421a0() + 0x5c);
        memset(buf, 0, 0x960);
        func_ov000_02176500(obj, buf, flag);
        TryApplyElemFields0205d5d0((struct StructA0205d5d0*)*(void**)((char*)obj + 0x38), 0xd, (int)buf, 1, 0);
    }
}
