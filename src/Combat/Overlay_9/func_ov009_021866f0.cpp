#include <globaldefs.h>

extern "C" void func_ov009_02188c2c(void* self);
extern "C" void func_ov009_02188d9c(void* self);
extern "C" void func_ov009_02188e70(void* self, unsigned char val);
extern "C" void func_ov009_02188944(void* self, unsigned char val);
extern "C" int func_ov009_02188ee8(void* self);
extern "C" ARM void _Z20SetStatValue021855dcPhi(unsigned char* self, int val);

int CallFunc020a0db8AtField0x16c(char* obj, int a, int b);
void CallFunc020a0db8AtField0x194AndClearFlag2(char* obj, int a, int b);

struct TripleWord { unsigned int a, b, c; };
extern struct TripleWord data_ov009_0218a9c8;
extern struct TripleWord data_ov009_0218a9d4;
extern struct TripleWord data_ov009_0218a9e0;
extern struct TripleWord data_ov009_0218a9ec;

// USA: func_ov009_021866f0  (semantic: AdvanceStatStep_021866f0)
extern "C" ARM void func_ov009_021866f0(unsigned char* self) {
    unsigned char step = self[0xc59];
    if (step == 0) {
        func_ov009_02188c2c(self);
        func_ov009_02188d9c(self);
        int idx = self[0xda3];
        unsigned char val = *(self + idx + 0xda6);
        func_ov009_02188e70(self, val);

        struct TripleWord buf1 = data_ov009_0218a9c8;
        struct TripleWord buf2 = data_ov009_0218a9d4;
        CallFunc020a0db8AtField0x16c((char*)self + 0x924, (int)&buf1, 0x1e000);
        CallFunc020a0db8AtField0x194AndClearFlag2((char*)self + 0x924, (int)&buf2, 0x1e000);

        *(unsigned int*)(self + 0xd9c) |= 1;
        self[0xc59] = self[0xc59] + 1;
        return;
    }
    if (step == 1) {
        if (*(unsigned int*)(self + 0xd9c) & 0x80) {
            return;
        }
        int idx = self[0xda3];
        unsigned char val = *(self + idx + 0xda6);
        func_ov009_02188944(self, val);
        self[0xc59] = self[0xc59] + 1;
        return;
    }
    if (step != 2) {
        return;
    }

    int result = func_ov009_02188ee8(self);
    int flag = 0;
    if (result == flag - 2) {
        _Z20SetStatValue021855dcPhi(self, 6);
        flag = 1;
    } else if (result == flag - 3) {
        _Z20SetStatValue021855dcPhi(self, 4);
        flag = 1;
    } else if (result >= 0x65 && result <= 0x6c) {
        int idx = self[0xda3];
        int v = result - 0x64;
        signed char arrv = *(signed char*)(self + idx + 0xda0);
        if (v <= arrv) {
            signed char cur = *(signed char*)(self + 0xc58);
            if (v != cur) {
                _Z20SetStatValue021855dcPhi(self, v & 0xff);
                flag = 1;
            }
        }
    }

    if (flag != 0) {
        struct TripleWord buf1b = data_ov009_0218a9e0;
        struct TripleWord buf2b = data_ov009_0218a9ec;
        CallFunc020a0db8AtField0x16c((char*)self + 0x924, (int)&buf1b, 0x1e000);
        CallFunc020a0db8AtField0x194AndClearFlag2((char*)self + 0x924, (int)&buf2b, 0x1e000);
    }
}
