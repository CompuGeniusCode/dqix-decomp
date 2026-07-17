#include <globaldefs.h>

extern "C" float func_ov017_021d6110(void*);
void* SetEntryTypeAndFields_0215913c(void* obj, int p1, int p2, int p3);

struct Data24_d608 { char pad[0x24]; void* field24; };
extern Data24_d608 data_ov001_02165880;

// USA: func_ov001_0215d608
ARM int SetEntryFromScaledFields_0215d608(void* self) {
    int v1 = (int)(4096.0f * func_ov017_021d6110(self));
    int v2 = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x8));
    int v3 = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x10));
    SetEntryTypeAndFields_0215913c(data_ov001_02165880.field24, v1, v2, v3);
    return 1;
}
