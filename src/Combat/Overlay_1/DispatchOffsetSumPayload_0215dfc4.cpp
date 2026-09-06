#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" float func_ov017_021d6110(void*);
extern "C" void* func_ov017_021d60f4(void*);
extern "C" int func_ov001_0215ab20(void*);

struct Payload3_02159250 { int c, d, e; };
void EnqueueEventType18_02159250(void* obj, int b, Payload3_02159250 payload);

struct Data24_0215dfc4 { char pad[0x24]; void* field24; };
extern Data24_0215dfc4 data_ov001_02165880;

// USA: func_ov001_0215dfc4
ARM int DispatchOffsetSumPayload_0215dfc4(void* self, int mode) {
    void* p = self;
    self = (char*)self + 0x8;
    int val = func_ov001_0215ab20(func_ov017_021d60f4(p));
    if (val == 0) {
        return 0;
    }
    Payload3_02159250 payload;
    memset(&payload, 0, 0xc);
    if (mode >= 2) {
        void* q = self;
        self = (char*)self + 0x8;
        payload.c += (int)(4096.0f * func_ov017_021d6110(q));
    }
    if (mode >= 3) {
        void* q = self;
        self = (char*)self + 0x8;
        payload.d += (int)(4096.0f * func_ov017_021d6110(q));
    }
    if (mode >= 4) {
        payload.e += (int)(4096.0f * func_ov017_021d6110(self));
    }
    EnqueueEventType18_02159250(data_ov001_02165880.field24, val, payload);
    return 1;
}
