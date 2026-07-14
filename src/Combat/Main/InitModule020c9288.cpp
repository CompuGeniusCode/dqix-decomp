#include <globaldefs.h>

struct Module020c9288 {
    unsigned short initialized;
    unsigned char pad2[2];
    int f4;
    int f8;
    int fc;
    int f10;
};

extern Module020c9288 data_02111654;
extern unsigned int DisableSpecificInterrupts(unsigned int mask);

// USA: func_020c9288
ARM void InitModule020c9288() {
    if (data_02111654.initialized != 0) {
        return;
    }
    data_02111654.initialized = 1;
    data_02111654.fc = 0;
    data_02111654.f10 = 0;
    DisableSpecificInterrupts(4);
    data_02111654.f8 = 0;
    data_02111654.f4 = 0;
}
