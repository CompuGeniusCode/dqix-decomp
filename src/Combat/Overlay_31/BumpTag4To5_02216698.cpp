#include <globaldefs.h>

struct SetTag0224e5dcStruct02216698 { int pad0; int pad4; int tag; };
extern SetTag0224e5dcStruct02216698 data_ov031_0224e5dc;

// USA: func_ov031_02216698
ARM void BumpTag4To5_02216698(void) {
    if (data_ov031_0224e5dc.tag == 4)
        data_ov031_0224e5dc.tag = 5;
}
