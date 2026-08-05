#include <globaldefs.h>

struct State0204166c;
void Forward020416c0(struct State0204166c* s);

int EncodeStreamFields020dc0e0(int a, int b, int c, int d, unsigned char e, unsigned char f);

extern "C" void func_020439b0(void* self, int flag);

extern int data_021077fc;
extern int data_020e7af8;

struct Target020432c4 {
    char pad0[0x68];
    unsigned int field68 : 16;
};

// USA: func_020432c4  (semantic: ResetCombatSlotsAndEncode020432c4)
extern "C" ARM void func_020432c4(char* obj) {
    struct Target020432c4* ptrField = *(struct Target020432c4**)(obj + 0x1e28);
    int i;

    if (ptrField != 0) {
        data_021077fc = ptrField->field68 << 3;
    }

    EncodeStreamFields020dc0e0(0, (int)&data_020e7af8, data_021077fc, 0x20, 1, 1);

    for (i = 0; i < 0x80; i++) {
        Forward020416c0((struct State0204166c*)(obj + 0x9b8 + i * 0x1c));
        *(unsigned char*)(obj + i + 0x17b8) = 0;
    }

    func_020439b0(obj, 0);
}
