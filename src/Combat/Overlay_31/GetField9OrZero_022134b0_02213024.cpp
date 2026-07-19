#include <globaldefs.h>

struct Obj0224e5c4_02213024 { unsigned char pad[0x17]; unsigned char field17; };
struct Glob0224e5c4_02213024 { unsigned char pad[0xc]; Obj0224e5c4_02213024* pField; };
extern Glob0224e5c4_02213024 data_ov031_0224e5c4;
ARM int GetField9OrZero_022134b0(void);

// USA: func_ov031_02213024  (semantic: GetField17IfTierInRange_02213024)
extern "C" ARM int func_ov031_02213024(void) {
    unsigned char result = 0xff;
    unsigned int v = GetField9OrZero_022134b0();
    if (v >= 0xa && v <= 0x10) {
        result = data_ov031_0224e5c4.pField->field17;
    }
    return result;
}
