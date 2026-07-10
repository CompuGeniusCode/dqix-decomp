#include <globaldefs.h>

struct Struct_020401e4;
ARM void ClearStruct020401e4(struct Struct_020401e4* obj);
extern "C" void func_0203cf58(void* obj);

// USA: func_0203ef60
ARM struct Struct_020401e4* ResetElement0203ef60(struct Struct_020401e4* obj) {
    ClearStruct020401e4(obj);
    func_0203cf58(obj);
    return obj;
}
