#include <globaldefs.h>

extern int data_02108760;
extern int data_ov001_0216587c;
void ForwardToTargetOrDefault0203acc8(void* obj, void* target, int arg);

// USA: func_ov001_021599b8
ARM int CallForwardToTargetOrDefault_021599b8(void) {
    ForwardToTargetOrDefault0203acc8(&data_02108760, &data_ov001_0216587c, 0);
    return 0;
}
