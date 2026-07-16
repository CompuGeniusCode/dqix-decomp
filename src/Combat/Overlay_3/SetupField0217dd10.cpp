#include <globaldefs.h>

int GetGlobalField0x1c020421a0();
struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
extern "C" void func_0204500c(void*, int, int, int);

// USA: func_ov003_0217dd10
ARM void SetupField0217dd10(char* obj, int key) {
    int g = GetGlobalField0x1c020421a0();
    int v = GetFieldByKey020e0434((struct Container020e0310*)(obj + 0xcc), (short)key);
    func_0204500c((void*)g, v, 0, 0xe3);
    *(unsigned char*)(g + 0x19b2) = 1;
    *(int*)(g + 0x99c) = 2;
}
