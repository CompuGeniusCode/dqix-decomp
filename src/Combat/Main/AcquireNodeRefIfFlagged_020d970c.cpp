#include <globaldefs.h>

extern "C" void* func_020c8074(void* node);

struct RefFlagState020d970c {
    char pad0[1];
    unsigned char flag1;
    unsigned char flag2;
    char pad3[1];
    int count;
};
extern struct RefFlagState020d970c data_0214e4a8;
extern int data_0214e4b0;

// USA: func_020d970c  (semantic: AcquireNodeRefIfFlagged_020d970c)
extern "C" ARM void func_020d970c(void) {
    if (data_0214e4a8.flag2 != 0 && data_0214e4a8.flag1 != 0) {
        func_020c8074(&data_0214e4b0);
        data_0214e4a8.count++;
    }
}
