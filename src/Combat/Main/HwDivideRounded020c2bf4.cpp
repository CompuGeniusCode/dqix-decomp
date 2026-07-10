#include <globaldefs.h>

void StartHwDivide(unsigned int numerHi, unsigned int denomLo);
int GetDivResultFixed20(void);

// USA: func_020c2bf4
ARM int HwDivideRounded020c2bf4(unsigned int numerHi, unsigned int denomLo) {
    StartHwDivide(numerHi, denomLo);
    return GetDivResultFixed20();
}
