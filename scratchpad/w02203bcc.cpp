#include <globaldefs.h>
#include "System/Timing.h"
#include "System/ProcessorContext.h"

struct GlobalStruct0224c980_02203bcc {
    char pad0[1];
    unsigned char field1;
    char pad1[0x18 - 2];
    void (*field18)(void);
    char pad2[0x48 - 0x18 - 4];
    int (*field48)(void);
    char pad3[0x50 - 0x48 - 4];
    void* field50;
};
extern GlobalStruct0224c980_02203bcc data_ov031_0224c980;

extern "C" void func_ov031_02200ccc(void* a);
extern "C" void func_ov031_02200160(int a);

// USA: func_ov031_02203bcc
extern "C" ARM void func_ov031_02203bcc(void) {
    data_ov031_0224c980.field18();
    if (data_ov031_0224c980.field50 == 0) return;
    func_ov031_02200ccc(data_ov031_0224c980.field50);
    SleepCurrentContext(0x64);
    func_ov031_02200ccc(data_ov031_0224c980.field50);
    int start = (int)(GetCurrentTimestamp() >> 16);
    while (data_ov031_0224c980.field48() != 0 &&
           (int)(GetCurrentTimestamp() >> 16) - start < 0x17) {
        if (data_ov031_0224c980.field1 != 0) {
            func_ov031_02200160(4);
            return;
        }
        SleepCurrentContext(0x64);
    }
}
