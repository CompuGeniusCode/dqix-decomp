#include <globaldefs.h>

struct Data0218fc8c { unsigned char pad[0x8]; int f8; unsigned char pad2[0x8]; int f14; int f18; };
extern struct Data0218fc8c data_ov016_0219d1c0;

// USA: func_ov016_0218fc8c
ARM void SetData_0218fc8c(void* a, unsigned int b) {
    data_ov016_0219d1c0.f18 = (int)a;
    data_ov016_0219d1c0.f14 = (int)(b & ~3u);
    data_ov016_0219d1c0.f8 = 0;
}
