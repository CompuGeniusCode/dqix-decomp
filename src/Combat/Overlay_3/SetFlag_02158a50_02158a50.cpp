// USA: func_ov003_02158a50
#include <globaldefs.h>

extern "C" void func_02036e34(void* obj, void* member, int arg3);
void ClearBitsInField0x6c(unsigned char* obj, unsigned int mask);
extern unsigned char data_ov003_0217fe16;

ARM void SetFlag_02158a50_02158a50(unsigned char* obj) {
    func_02036e34(obj + 0x280, &data_ov003_0217fe16, 9);
    ClearBitsInField0x6c(obj + 0x280, 0x40000);
    *(int*)(obj + 0x32c) = 1;
}
