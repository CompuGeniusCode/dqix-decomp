#include <globaldefs.h>

struct StateHolder02210ef8 {
    int* state;
};

extern StateHolder02210ef8 data_ov031_0224e588;

// USA: func_ov031_02210ef8
ARM int IsStateSeven_02210ef8(void) {
    if (data_ov031_0224e588.state == NULL) {
        return 0;
    }
    return *data_ov031_0224e588.state == 7;
}
