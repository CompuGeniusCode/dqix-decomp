#include <globaldefs.h>

struct Struct02165880 {
    unsigned char pad0[0x28];
    int counter;
};
extern struct Struct02165880 data_ov001_02165880;

// USA: func_ov001_021622f0
ARM void IncrementCounterBy1_021622f0(void) {
    data_ov001_02165880.counter += 1;
}
