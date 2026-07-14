#include <globaldefs.h>

extern char data_020f296c;
extern char data_020f297e;
void ComputeAndApplyWithCounter020e54bc(int, void*, int, int, unsigned char, int);

// USA: func_020dcf7c
ARM void DispatchIfCountPositive020dcf7c(int count, void* buf) {
    if (count <= 0) return;
    if (buf == NULL) return;
    ComputeAndApplyWithCounter020e54bc((int)buf, &data_020f296c, count, 0, 1, (int)&data_020f297e);
}
