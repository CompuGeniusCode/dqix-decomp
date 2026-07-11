#include <globaldefs.h>
void TransferBg1CharData(int, int, unsigned int);
void TransferSubBg0CharData(int, int, unsigned int);

extern void* data_020fe9a4;

// USA: func_020290ac
ARM void FlushOrClearBuffer020290ac(int flag) {
    if (data_020fe9a4 == NULL) return;
    if (flag == 0) {
        TransferBg1CharData((int)(data_020fe9a4), (int)(0), (unsigned int)(0x6000));
    } else {
        TransferSubBg0CharData((int)(data_020fe9a4), (int)(0), (unsigned int)(0x6000));
    }
}
