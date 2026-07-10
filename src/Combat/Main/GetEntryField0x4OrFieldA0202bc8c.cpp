#include <globaldefs.h>

struct SearchStruct;
extern "C" int func_0202c508(struct SearchStruct* obj);
unsigned short GetField0xa(void);
void* GetEntryBySignedByteIndex(struct SearchStruct* obj, int value);

// USA: func_0202bc8c
ARM unsigned short GetEntryField0x4OrFieldA0202bc8c(struct SearchStruct* obj) {
    if (func_0202c508(obj)) {
        return GetField0xa();
    }
    return *(unsigned short*)((char*)GetEntryBySignedByteIndex(obj, 0) + 4);
}
