#include <globaldefs.h>

int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern "C" int func_0205d97c(int);
extern "C" void func_ov000_0217629c(void* obj);
extern "C" void func_ov000_0217ab8c(void* obj, int a, int b);
extern "C" void func_ov000_02176e3c(int a, void* obj, int c, int d, int e, int f);

extern unsigned short data_02114e30;
extern int data_ov000_02184294[3];

// USA: func_ov000_0217bfbc
extern "C" ARM int func_ov000_0217bfbc(void* objRaw, int arg1, int arg2) {
    char* obj = (char*)objRaw;
    int flags = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601);
    flags |= TestFlag0SetAndFlag1Clear(&data_02114e30, 0x802);
    int c = (func_0205d97c(*(int*)(obj + 0x38)) == 2) ? 1 : 0;
    if ((flags | c) != 0) {
        *(unsigned char*)(obj + 0x444) = 0;
        func_ov000_0217629c(obj);
        signed char idx = *(signed char*)(obj + 0x18);
        *(unsigned char*)(obj + idx + 0x10) = 0;
        idx = *(signed char*)(obj + 0x18);
        *(unsigned char*)(obj + 0x18) = idx - 1;
        func_ov000_0217ab8c(obj, arg1, arg2);
        signed char idx2 = *(signed char*)(obj + 0x18);
        signed char p2 = *(signed char*)(obj + idx2 + 0x10);
        func_ov000_02176e3c(data_ov000_02184294[2], obj, p2, data_ov000_02184294[1], data_ov000_02184294[0], 0);
    }
    return -1;
}
