#include <globaldefs.h>

struct Data24_d134 { char pad[0x24]; void* field24; };
extern Data24_d134 data_ov001_02165880;
struct DataE4_d134 { char pad[0xe4]; int fieldE4; };
extern DataE4_d134 data_ov001_021658b8;
extern "C" void func_ov001_021588e4(void* p);

// USA: func_ov001_0215d134
ARM int InitAndSetFieldE4_0215d134(void) {
    func_ov001_021588e4(data_ov001_02165880.field24);
    if (data_ov001_021658b8.fieldE4 == 0) data_ov001_021658b8.fieldE4 = 1;
    return 1;
}
