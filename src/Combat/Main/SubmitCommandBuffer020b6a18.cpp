#include <globaldefs.h>

void ResetCommandQueue(void);
void ClearField0020b6a0c(int* field);

extern "C" void func_020b6acc(int header, void* data, unsigned int wordCountMinus1);
extern "C" void func_020ca2ac(int val, void* buf, unsigned int size, void (*cb)(int*), int* addr);
extern "C" void func_020ca0a8(int val, void* buf, unsigned int size, void (*cb)(int*), int* addr);

extern int data_020f2270;
extern volatile int data_0210cf78[];
extern int data_0210cf7c;

// USA: func_020b6a18
ARM void SubmitCommandBuffer020b6a18(void* buf, unsigned int size) {
    if (size < 0x100 || data_020f2270 == -1) {
        func_020b6acc(*(int*)buf, (char*)buf + 4, (size >> 2) - 1);
        return;
    }
    ResetCommandQueue();
    data_0210cf78[1] = 1;
    if (data_0210cf78[2] != 0) {
        func_020ca2ac(data_020f2270, buf, size, ClearField0020b6a0c, &data_0210cf7c);
    } else {
        func_020ca0a8(data_020f2270, buf, size, ClearField0020b6a0c, &data_0210cf7c);
    }
}
