#include <globaldefs.h>
void InitWithExtendedRegion0203cf58(struct Struct_0203cf58*);

struct Struct_020401e4;
ARM void ClearStruct020401e4(struct Struct_020401e4* obj);

// USA: func_0203ef60
ARM struct Struct_020401e4* ResetElement0203ef60(struct Struct_020401e4* obj) {
    ClearStruct020401e4(obj);
    InitWithExtendedRegion0203cf58((struct Struct_0203cf58*)(obj));
    return obj;
}
