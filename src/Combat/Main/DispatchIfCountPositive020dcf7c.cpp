#include <globaldefs.h>

extern char data_020f296c;
extern char data_020f297e;
extern "C" void func_020e54bc(void*, void*, int, int, int, void*);

// USA: func_020dcf7c
ARM void DispatchIfCountPositive020dcf7c(int count, void* buf) {
    if (count <= 0) return;
    if (buf == NULL) return;
    func_020e54bc(buf, &data_020f296c, count, 0, 1, &data_020f297e);
}
