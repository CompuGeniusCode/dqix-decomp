#include <globaldefs.h>

void ClearField0x5cBit0(unsigned int* obj);
extern "C" void func_02041538(void* obj);

// USA: func_02040bcc
ARM void ClearActiveChildState(char* self) {
    void* a = *(void**)(self + 0x14);
    if (a != NULL) {
        ClearField0x5cBit0((unsigned int*)a);
        return;
    }
    void* b = *(void**)(self + 0x18);
    if (b == NULL) return;
    func_02041538(b);
}
