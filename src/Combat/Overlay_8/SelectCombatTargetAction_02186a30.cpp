#include <globaldefs.h>

extern "C" void _Z22SelectCoordsByFlag0x24PhPiS0_(unsigned char* table, int* out1, int* out2);
extern "C" int func_ov008_02186b18(void* obj, int a, int b);
extern "C" void func_0205bb04(void* p, int id);
extern "C" void func_0205bf58(void* p, int a2);

extern int data_02114e54;

// USA: func_ov008_02186a30
extern "C" ARM int func_ov008_02186a30(void* obj, int a2) {
    int coordA, coordB;
    int flag = 0;
    int id = -1;

    _Z22SelectCoordsByFlag0x24PhPiS0_((unsigned char*)&data_02114e54, &coordA, &coordB);

    if (*((unsigned char*)&data_02114e54 + 0x55) != 0) {
        flag = 1;
        id = func_ov008_02186b18(obj, coordA, coordB);
        if (id != -1) {
            func_0205bb04((char*)obj + 0x750, id);
        }
    } else if (*((unsigned char*)&data_02114e54 + 0x5f) != 0) {
        if (*(unsigned short*)((char*)&data_02114e54 + 0x24) != 0) {
            flag = 1;
        }
    } else if (*((unsigned char*)&data_02114e54 + 0x54) != 0) {
        flag = 1;
    }

    if (flag == 0) {
        func_0205bf58((char*)obj + 0x750, a2);
    }
    if (flag != 0) {
        if (id == -1) {
            return 0;
        } else if (id == -2) {
            return -2;
        } else if (id >= 0) {
            return 1;
        }
    }
    return 0;
}
