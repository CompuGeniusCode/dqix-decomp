#include <globaldefs.h>

extern "C" int func_ov012_02184384(int a, int b);
struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void func_ov023_021e6e60(void* obj);
void BuildMessageE_0218a438(char* self);
struct Struct_0205c570;
int GetActiveScaledSum0205d794(struct Struct_0205c570* s);
extern "C" int func_ov023_021e6de4(char* obj);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
struct Obj021e6e20;
int TestFlagsAndActiveElement2_021e6e20(struct Obj021e6e20* obj);
extern "C" void func_ov012_0218930c(void* obj, int a);
extern int data_02108760;

// USA: func_ov012_021884f4  (semantic: AdvanceTagState_021884f4)
extern "C" ARM void func_ov012_021884f4(char* base) {
    unsigned char state = *(unsigned char*)(base + 0x1000 + 0x370);
    if (state == 0) {
        *(unsigned char*)(base + 0x1000 + 0x3a0) = 0;
        *(int*)(base + 0x1000 + 0x3e8) = 1;

        unsigned short raw = *(unsigned short*)(base + 0x1300 + 0xc4);
        unsigned int field = (unsigned int)raw << 16;
        field = field >> 21;
        int ret = func_ov012_02184384(*(int*)(base + 0x1000 + 0x3c8), field);
        if (ret < 0) {
            *(int*)(base + 0x1000 + 0x3e8) = 0;
        }

        FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(base + 0xac), 0, 3);
        func_ov023_021e6e60(base);
        BuildMessageE_0218a438(base);

        (*(unsigned char*)(base + 0x1000 + 0x370))++;
        return;
    }
    if (state != 1) return;

    *(unsigned char*)(base + 0x1000 + 0x3a0) = 1;
    int sum = GetActiveScaledSum0205d794((struct Struct_0205c570*)(base + 0xac));
    *(int*)(base + 0x1000 + 0x3e8) = sum;

    if (func_ov023_021e6de4(base) != 0) {
        int v = *(int*)(base + 0x1000 + 0x3e8);
        int cont = 1;
        switch (v) {
        case 0:
            *(unsigned char*)(base + 0x1000 + 0x371) = 0xb;
            *(unsigned char*)(base + 0x1000 + 0x370) = 0;
            break;
        case 1: {
            unsigned short raw2 = *(unsigned short*)(base + 0x1300 + 0xc4);
            unsigned int field2 = (unsigned int)raw2 << 16;
            field2 = field2 >> 21;
            if (field2 != 0) {
                *(unsigned char*)(base + 0x1000 + 0x371) = 0xc;
                *(unsigned char*)(base + 0x1000 + 0x370) = 0;
            } else {
                cont = 0;
            }
            break;
        }
        }

        if (cont != 0) {
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 1, 0);
        }
    } else {
        if (TestFlagsAndActiveElement2_021e6e20((struct Obj021e6e20*)base) != 0) {
            func_ov012_0218930c(base, 1);
        }
    }
}
