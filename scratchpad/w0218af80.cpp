#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
int CheckField0x14Or0x20Positive(int* obj);
extern "C" void func_020a1940(int);
extern "C" void func_ov008_021843f8(void* obj);
extern "C" void func_ov008_021842a0(void* a, void* b);
void SetByteB10AndClearB11_02184a3c(char* obj, unsigned char val);
void OrGlobalFlag0x40(void);
extern "C" void func_0203b19c(int base, int a, int b);

struct Flags0218af80 {
    char pad[0xec0];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
};

// USA: func_ov008_0218af80
extern "C" ARM void func_ov008_0218af80(char* obj) {
    int v = func_ov017_0218b5b0();
    if (*(signed char*)(obj + 0xe9c) == 0) {
        if (((struct Flags0218af80*)obj)->b1) {
            if (CheckField0x14Or0x20Positive((int*)v) == 0) {
                func_020a1940(8);
                func_ov008_021843f8(obj + 0x2a8);
                *(int*)(obj + 0xdcc) = 1;
                func_ov008_021842a0(obj + 0x2a8, obj + 0x228);
                SetByteB10AndClearB11_02184a3c(obj + 0x2a8, 1);
                *(void**)(obj + 0xde4) = obj + 0x288;
                void* ebc = *(void**)(obj + 0xebc);
                void* p0;
                void* p1;
                if (ebc == 0) {
                    p0 = obj + 0xdf6;
                    p1 = obj + 0xe04;
                } else {
                    p0 = ebc;
                    p1 = (char*)ebc + 0x38;
                }
                *(void**)(obj + 0xdd8) = p0;
                *(void**)(obj + 0xddc) = p1;
                *(signed char*)(obj + 0xe9c) = *(signed char*)(obj + 0xe9c) + 1;
                return;
            }
        }
    }
    if (*(signed char*)(obj + 0xe9c) != 1) return;
    if (!((struct Flags0218af80*)obj)->b1) return;
    if (!((struct Flags0218af80*)obj)->b2) return;
    OrGlobalFlag0x40();
    func_0203b19c(v, -16, 15);
    *(signed char*)(obj + 0xe9b) = 1;
    *(signed char*)(obj + 0xe9c) = 0;
}
