#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(unsigned char* self);
extern "C" void func_0203b110(void* p, int a, int b);
extern "C" int func_02012fe4(void);
extern "C" void func_02098630(void* obj, void* addr, int a, int b);

int CheckField0x14Positive(int* p);
void ResetFieldsB68AndB74_0216fb6c(char* obj);

// USA: func_ov003_021733d0
ARM void UpdateCombatState_021733d0(unsigned char* self) {
    int* p = (int*)func_ov017_0218b5b0(self);
    if (self[0xee] == 0) {
        func_0203b110(p, -16, 24);
        self[0xee] = 1;
        return;
    }
    if (self[0xee] != 1) {
        return;
    }
    if (CheckField0x14Positive(p) != 0) {
        return;
    }
    int r4 = func_02012fe4();
    if (self[0xcc] == 0) {
        ResetFieldsB68AndB74_0216fb6c((char*)r4 + 0x840);
        for (int i = 0; i < self[0xd5]; i++) {
            void* addr = (char*)*(int*)(self + 0xd0) + 0x460 + (unsigned char)i * 0xe8;
            func_02098630((char*)r4 + 0x840, addr, 1, 0);
        }
        ResetFieldsB68AndB74_0216fb6c((char*)r4 + 0x840);
    }
    self[0xec] = 6;
    self[0xee] = 0;
}
