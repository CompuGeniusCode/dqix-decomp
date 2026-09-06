#include <globaldefs.h>
#include "std_library_functions.h"

struct Container021e8cc0;
extern "C" void _Z30CallAppendStringIfSet_021e8cc0P17Container021e8cc0(struct Container021e8cc0* obj);
extern "C" void func_ov023_021e8cdc(void* obj);

struct StructA0205d5d0;
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);

// USA: func_ov023_021e81f4
ARM void ApplyElemFieldsTwice_021e81f4(void* obj) {
    memset(*(void**)((char*)obj + 0x5d8), 0, 0x960);
    _Z30CallAppendStringIfSet_021e8cc0P17Container021e8cc0((struct Container021e8cc0*)obj);
    _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0*)((char*)obj + 0x78), 0xc, *(int*)((char*)obj + 0x5d8), 0, 1);

    memset(*(void**)((char*)obj + 0x5d8), 0, 0x960);
    func_ov023_021e8cdc(obj);
    _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0*)((char*)obj + 0x78), 0xd, *(int*)((char*)obj + 0x5d8), 0, 1);
}
