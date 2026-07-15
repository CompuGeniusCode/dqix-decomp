#include <globaldefs.h>

struct Struct02162308 {
    unsigned char pad0[0x28];
    int counter;
};
extern struct Struct02162308 data_ov001_02165880;

// USA: func_ov001_02162308
ARM void IncrementCounterBy2_02162308(void) {
    data_ov001_02165880.counter += 2;
}
