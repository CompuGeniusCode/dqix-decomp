#include <globaldefs.h>

extern int data_ov028_021d9aec;
extern int data_ov028_021d9b14;
extern "C" unsigned int _Z17DisarmVCountAlarmP16AlarmCtx020c949c(unsigned int);
extern "C" unsigned int _Z20ResetFields_021d94e4Pv(unsigned int);

// USA: func_ov028_021d9714  (semantic: Trans_021d9714)
extern "C" ARM unsigned int func_ov028_021d9714(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    r0 = (unsigned int)&data_ov028_021d9aec;
    r0 = (unsigned int)_Z17DisarmVCountAlarmP16AlarmCtx020c949c(r0);
    r0 = (unsigned int)&data_ov028_021d9b14;
    r0 = (unsigned int)_Z20ResetFields_021d94e4Pv(r0);
    return r0;
}
