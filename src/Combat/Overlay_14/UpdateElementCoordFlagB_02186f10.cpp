#include <globaldefs.h>

extern unsigned short data_02114e30;
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);

extern unsigned char data_02114e54;
void SelectCoordsByFlag0x24(unsigned char* obj, int* out1, int* out2);

int RunAndCheckFlagBit02080dd4(void* obj, int p1, int unused2, int unused3, unsigned char* outFlag, unsigned char extra);
extern "C" void func_020813ec(void* obj, int key);

// USA: func_ov014_02186f10  (semantic: UpdateElementCoordFlagB_02186f10)
extern "C" ARM int func_ov014_02186f10(char* self) {
    unsigned char flag = 0;

    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x401)) {
        flag = 1;
    }

    if (*(&data_02114e54 + 0x55) != 0 && *(short**)(self + 0xd0) != 0) {
        int a, b;
        SelectCoordsByFlag0x24(&data_02114e54, &a, &b);
        int result = RunAndCheckFlagBit02080dd4(*(void**)(self + 0xc0), *(short*)(self + 0x170), (short)a, (short)b, &flag, 1);
        if (result < 0) {
            return 0;
        }
        *(*(short**)(self + 0xd0)) = (short)result;
        short cur = *(*(short**)(self + 0xd0));
        if (*(short*)(self + 0x178) != cur) {
            *(short*)(*(char**)(self + 0xc0) + 0x36) = cur;
            func_020813ec(*(void**)(self + 0xc0), *(short*)(self + 0x170));
        }
    }

    return flag;
}
