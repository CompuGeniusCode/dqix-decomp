#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern "C" void RefreshRefIfFlagged_02217e70(char *self);
extern "C" int func_ov031_022169a0(void);

extern void* data_ov031_0224e60c;

// USA: func_ov031_02219178
ARM void Update0224e60c_02219178(void) {
    void* ptr = data_ov031_0224e60c;
    if (ptr == 0) {
        return;
    }
    char* val14 = *(char**)((char*)&data_ov031_0224e60c + 0x14);
    if (val14 != 0) {
        RefreshRefIfFlagged_02217e70(val14);
    }
    func_ov031_022169a0();
    if (*(int*)((char*)data_ov031_0224e60c + 0x1000 + 0x188) != 0) {
        AwaitContextCompletion((ProcessorContext*)((char*)data_ov031_0224e60c + 0x11c + 0x1000));
    }
    *(int*)((char*)data_ov031_0224e60c + 0x1000 + 4) = -7;
}
