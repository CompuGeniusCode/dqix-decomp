#include <globaldefs.h>

struct InitStruct;
struct ResetObject0209af34Struct;
struct ZeroWordAndByte0206ee70Struct;

ARM void InitializeStruct(struct InitStruct* s);
ARM void ClearBuffer0209bc84(void* obj);
ARM void ResetObject0209af34(struct ResetObject0209af34Struct* obj);
ARM void ZeroWordAndByte0206ee70(struct ZeroWordAndByte0206ee70Struct* s);

// USA: func_02028cfc
ARM void* FinalizeSubObjects02028cfc(void* obj) {
    ZeroWordAndByte0206ee70((struct ZeroWordAndByte0206ee70Struct*)((char*)obj + 0x304));
    ResetObject0209af34((struct ResetObject0209af34Struct*)((char*)obj + 0x124));
    ClearBuffer0209bc84((char*)obj + 0x60);
    InitializeStruct((struct InitStruct*)((char*)obj + 0x18));
    return obj;
}
