#include <globaldefs.h>

extern int data_ov031_02291e04;

// USA: func_ov031_022433d0
extern "C" ARM void func_ov031_022433d0(int a, int flag) {
    switch (flag) {
    case 0:
        if (a == 3) {
            *(int*)((char*)&data_ov031_02291e04 + 0x14) = 1;
        }
        break;
    }
    *(int*)((char*)&data_ov031_02291e04 + 0xc) = 1;
    if (flag != 0) {
        *(int*)((char*)&data_ov031_02291e04 + 0x24) = 1;
    }
}
