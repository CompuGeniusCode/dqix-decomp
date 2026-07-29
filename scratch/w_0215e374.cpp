#include <globaldefs.h>

int GetGlobalField0x1c020421a0();
extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov001_0215e374
ARM int SetFieldFromGlobalByte9bd_0215e374(void* self) {
    int r = GetGlobalField0x1c020421a0();
    unsigned char v = *(unsigned char*)(r + 0x1000 + 0x9bd);
    func_ov017_021d6134(self, v);
    return 1;
}
