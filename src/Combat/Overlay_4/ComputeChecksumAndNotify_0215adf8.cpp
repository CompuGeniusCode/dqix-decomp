#include <globaldefs.h>

struct Struct021707d8_0215adf8 { char pad[8]; char* ptr; };
extern Struct021707d8_0215adf8 data_ov004_021707d8;

extern "C" double func_0200b074(int);
extern "C" double func_020095a4(double, double);
extern "C" int func_0200af44(double);
extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_0215adf8
ARM int ComputeChecksumAndNotify_0215adf8(void* obj) {
    int i;
    *(int*)(data_ov004_021707d8.ptr + 0x78) = 0;
    for (i = 0; i < 7; i++) {
        double di = func_0200b074(i);
        int weight = func_0200af44(func_020095a4(10.0, di));
        signed char digit = *(signed char*)(data_ov004_021707d8.ptr + i + 0x3f);
        int total = *(int*)(data_ov004_021707d8.ptr + 0x78);
        total = weight * digit + total;
        *(int*)(data_ov004_021707d8.ptr + 0x78) = total;
    }
    *(unsigned char*)(data_ov004_021707d8.ptr + 0x6e) = 1;
    if (*(unsigned char*)(data_ov004_021707d8.ptr + 0x6f) == 1) {
        func_ov011_021848a0(obj, 0x39c);
    } else {
        func_ov011_021848a0(obj, 0x6d);
    }
    return 0;
}
