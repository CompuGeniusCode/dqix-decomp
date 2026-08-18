#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

struct InitStruct02075cdcStruct;
void InitStruct02075cdc(struct InitStruct02075cdcStruct* s);
extern "C" void* func_0203bd08(void);
extern "C" void* func_0203be4c(void);
struct StructDE234_020de234;
unsigned short GetPreferredPackedField020de234(struct StructDE234_020de234* p, int preferMid);

extern char data_ov006_02160360[];

// USA: func_ov006_0215fe34
extern "C" ARM void func_ov006_0215fe34(char* self, struct StructDE234_020de234* info) {
    if (info == NULL) {
        return;
    }

    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    InitStruct02075cdc((struct InitStruct02075cdcStruct*)(self + 0x3b8));
    *(int*)(self + 0x3f4) = 5;
    *(unsigned char*)(self + 0x416) = 1;

    func_0203bd08();
    void* p = func_0203be4c();
    *(char**)(self + 0x3cc) = (char*)p + 0x1b8;

    *(int*)(self + 0x3f0) = 0x10000;
    *(int*)(self + 0x3f8) = 0;

    unsigned short val = GetPreferredPackedField020de234(info, 0);

    unsigned int raw10 = *(unsigned int*)((char*)info + 0x10);
    int percent = (raw10 << 4) >> 0x18;

    char buf[0x40];
    sprintf(buf, data_ov006_02160360, percent, val);

    int r = loader->QueueLoadFile((const char*)buf, (SafeAllocator*)0);
    *(int*)(self + 0x428) = r;
}
