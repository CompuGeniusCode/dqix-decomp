#include <globaldefs.h>
#pragma optimize_for_size off

struct Table0221f994 {
    int pad[11];
    int field2c;
};

extern Table0221f994 data_ov031_0224f670;

// USA: func_ov031_0221f994  (semantic: GetGlobalField2c_0221f994)
extern "C" THUMB int func_ov031_0221f994(void) {
    return data_ov031_0224f670.field2c;
}
