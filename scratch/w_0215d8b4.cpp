#include <globaldefs.h>

void* EnqueueEventType9_021590c4(void* ctx);

struct Data24_0215d8b4 { char pad[0x24]; void* field24; };
extern Data24_0215d8b4 data_ov001_02165880;

// USA: func_ov001_0215d8b4
ARM int EnqueueEventType9Wrapper_0215d8b4(void) {
    EnqueueEventType9_021590c4(data_ov001_02165880.field24);
    return 1;
}
