#include <globaldefs.h>
#include "std_library_functions.h"

struct StructA0205d5d0;
int TryApplyElemFields0205d5d0(struct StructA0205d5d0*, int, int, int, unsigned char);
extern "C" void func_ov013_02185be0(void*, void*);

// USA: func_ov013_02186c1c  (semantic: ApplyElemFieldsSlot3_02186c1c)
extern "C" ARM void func_ov013_02186c1c(void* obj) {
    memset(*(void**)((char*)obj + 0x658), 0, 0x960);
    func_ov013_02185be0(obj, *(void**)((char*)obj + 0x658));
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x38), 3, *(int*)((char*)obj + 0x658), 1, 1);
}
