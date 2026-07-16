#include <globaldefs.h>

struct Data0218cf34 { unsigned char pad[0x44]; unsigned long long counter; };
extern struct Data0218cf34 data_ov016_0219d144;

// USA: func_ov016_0218cf34
ARM void IncCounter_0218cf34(void) {
    data_ov016_0219d144.counter++;
}
