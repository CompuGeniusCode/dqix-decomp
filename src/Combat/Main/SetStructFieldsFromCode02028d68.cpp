#include <globaldefs.h>

struct DataStruct02028d68 {
    char pad0[4];
    int val4;
    int val8;
    int valc;
};
extern struct DataStruct02028d68 data_020ef74c;

// USA: func_02028d68
ARM void SetStructFieldsFromCode02028d68(int code) {
    data_020ef74c.valc = code;
    if (code == 0) {
        data_020ef74c.val4 = 8;
        data_020ef74c.val8 = 8;
        return;
    }
    if ((unsigned int)(code - 1) <= 1) {
        data_020ef74c.val8 = 6;
        data_020ef74c.val4 = 0xc;
        return;
    }
    if ((unsigned int)(code - 3) <= 1) {
        data_020ef74c.val8 = 5;
        data_020ef74c.val4 = 0xa;
        return;
    }
    if ((unsigned int)(code - 5) <= 1) {
        data_020ef74c.val8 = 6;
        data_020ef74c.val4 = 0xc;
    }
}
