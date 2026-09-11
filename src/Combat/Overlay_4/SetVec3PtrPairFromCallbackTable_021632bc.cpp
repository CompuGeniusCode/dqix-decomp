#include <globaldefs.h>

extern "C" void* func_ov004_0215e47c(void* a, int key);
void* GetCallbackTableAndCount_02184a30(void* obj, unsigned int* outCount);

// USA: func_ov004_021632bc  (semantic: SetVec3PtrPairFromCallbackTable_021632bc)
extern "C" ARM int func_ov004_021632bc(void* self) {
    void* node = func_ov004_0215e47c(self, 0x82);
    if (node == NULL) return 0;
    unsigned int count = 0;
    void* table = GetCallbackTableAndCount_02184a30(self, &count);
    void* v1 = (char*)table + 0x2c;
    char* dest = (char*)node;
    dest += 0x1000;
    void* v2 = (char*)table + 0x30;
    *(void**)(dest + 0x868) = v1;
    *(void**)(dest + 0x86c) = v2;
    return 0;
}
