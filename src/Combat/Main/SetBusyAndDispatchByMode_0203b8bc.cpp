#include <globaldefs.h>

extern "C" void func_0203b97c(void* a, void* data, int c1, int c2, int d, int e, int f, int g, int h, unsigned short i);

extern int data_021065d8;
extern int data_02105fd8;

// USA: func_0203b8bc  (semantic: SetBusyAndDispatchByMode_0203b8bc)
extern "C" ARM void func_0203b8bc(void* a, int b, int c, int d, int e, int f, int g, int h, unsigned short i) {
    int* p = (int*)a + (c + b * 4);
    p[0x10] = 1;
    if (b == 1) {
        switch (c) {
        case 0:
            func_0203b97c(a, &data_021065d8, 0x40, 0x20, d, e, f, g, h, i);
            break;
        case 1:
            func_0203b97c(a, &data_02105fd8, 0x20, 0x18, d, e, f, g, h, i);
            break;
        }
    }
}
