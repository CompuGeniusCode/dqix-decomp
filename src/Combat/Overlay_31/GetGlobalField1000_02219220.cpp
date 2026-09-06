#include <globaldefs.h>
struct GlobalStruct02219220 { unsigned char pad[0x1000 + 4]; int field1000; };
extern GlobalStruct02219220 *data_ov031_0224e60c;
// USA: func_ov031_02219220
ARM int GetGlobalField1000_02219220(void) {
    return data_ov031_0224e60c->field1000;
}
