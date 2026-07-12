#include <globaldefs.h>

extern unsigned int data_0211173c;
void InitAndInvoke020d0008(int a);
void PrepareAndCommit020d0024(int a);

// USA: func_020ccd48
ARM int DispatchExMemAction(void* unused, int selector) {
    switch (selector) {
    case 9:
        InitAndInvoke020d0008((unsigned short)data_0211173c);
        return 0;
    case 10:
        PrepareAndCommit020d0024((unsigned short)data_0211173c);
        return 0;
    case 1:
        return 4;
    default:
        return 8;
    }
}
