#include <globaldefs.h>

extern int data_ov031_02290ce8;
void TailCallForward_0223e2e0(int, int);
void FreeAndClearPtr_0223cf70(void*);

// USA: func_ov031_02234f08
ARM void NotifyAndRegister_02234f08(void) {
    TailCallForward_0223e2e0(1, *(int*)data_ov031_02290ce8);
    FreeAndClearPtr_0223cf70(&data_ov031_02290ce8);
}
