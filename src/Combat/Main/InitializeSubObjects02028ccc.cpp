#include <globaldefs.h>

struct InitStruct;
struct ResetObject0209af34Struct;
struct ZeroWordAndByte0206ee60Struct;

ARM void InitializeStruct(struct InitStruct* s);
ARM void ClearBuffer0209bc84(void* obj);
ARM void ResetObject0209af34(struct ResetObject0209af34Struct* obj);
ARM void ZeroWordAndByte0206ee60(struct ZeroWordAndByte0206ee60Struct* s);

// USA: func_02028ccc
ARM void* InitializeSubObjects02028ccc(void* obj) {
    InitializeStruct((struct InitStruct*)((char*)obj + 0x18));
    ClearBuffer0209bc84((char*)obj + 0x60);
    ResetObject0209af34((struct ResetObject0209af34Struct*)((char*)obj + 0x124));
    ZeroWordAndByte0206ee60((struct ZeroWordAndByte0206ee60Struct*)((char*)obj + 0x304));
    return obj;
}
