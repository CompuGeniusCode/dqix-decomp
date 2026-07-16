#include <globaldefs.h>

struct Data0218bcc4 { unsigned char pad[0x48]; unsigned long long counter; };
extern struct Data0218bcc4 data_ov016_0219d0c0;

// USA: func_ov016_0218bcc4
ARM void IncCounter_0218bcc4(void) {
    data_ov016_0219d0c0.counter++;
}
