#include <globaldefs.h>
#include "System/Memory.h"

ARM void* CallWithConst32_02211b54(void* a, void* b);
ARM int GetBufferSize1da0_02215fcc(void);

struct Buf022162f0 { char pad[0x790]; void* fieldB; };
struct Global0224e5dcStruct022162f0 { void* field0; void* field4; int field8; };
extern Global0224e5dcStruct022162f0 data_ov031_0224e5dc;

// USA: func_ov031_022162f0  (semantic: RegisterAAndB_022162f0)
extern "C" ARM int func_ov031_022162f0(void* a, void* b) {
    data_ov031_0224e5dc.field4 = CallWithConst32_02211b54((void*)1, (void*)GetBufferSize1da0_02215fcc());
    data_ov031_0224e5dc.field0 = CallWithConst32_02211b54((void*)1, (void*)0x794);
    VectorizedMemset(data_ov031_0224e5dc.field0, 0, 0x794);
    *(void**)data_ov031_0224e5dc.field0 = a;
    ((Buf022162f0*)data_ov031_0224e5dc.field0)->fieldB = b;
    data_ov031_0224e5dc.field8 = 0;
    return 1;
}
