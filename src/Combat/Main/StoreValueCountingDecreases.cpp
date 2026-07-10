#include <globaldefs.h>

unsigned int DisableInterrupts(void);
unsigned int RestoreInterrupts(unsigned int mask);

struct Global02111654 { int f0; int f4; int f8; };
extern Global02111654 data_02111654;

// USA: func_020c96a8
ARM int StoreValueCountingDecreases(int value) {
    unsigned int mask;
    mask = DisableInterrupts();
    if (value < data_02111654.f4) {
        data_02111654.f8++;
    }
    data_02111654.f4 = value;
    RestoreInterrupts(mask);
    return data_02111654.f8;
}
