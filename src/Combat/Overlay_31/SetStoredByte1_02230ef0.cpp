#include <globaldefs.h>

struct DataHolder02290ca0 {
    unsigned char unk0;
    unsigned char unk1;
};
extern struct DataHolder02290ca0 data_ov031_02290ca0;

// USA: func_ov031_02230ef0
ARM void SetStoredByte1_02230ef0(unsigned char val) {
    data_ov031_02290ca0.unk1 = val;
}
