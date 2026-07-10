#include <globaldefs.h>

extern unsigned short data_02108d70[];

// USA: func_02071688
ARM void InitHalfwords02071688(void) {
    data_02108d70[1] = 0x21c;
    data_02108d70[3] = 0x302;
}
