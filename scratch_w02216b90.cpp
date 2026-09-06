#include <globaldefs.h>
#include "System/ProcessorContext.h"
#include "std_library_functions.h"

struct Glob0224e5e8_02216b90 { char pad[8]; char* base; };
extern Glob0224e5e8_02216b90 data_ov031_0224e5e8;

struct Struct02249b54_02216b90 {
    char* namePtr;
    char pad4[8];
    int fieldC;
    int field10;
    int field14;
};
extern Struct02249b54_02216b90 data_ov031_02249b54;
extern char data_ov031_02249bb8[];
extern int data_ov031_0224e5f4;

extern "C" int func_ov031_02217c00(void* p);
extern "C" void func_ov031_0221ae00(void* p);
extern "C" int func_ov031_022173f4(int a0, void* a1, void* a2);
extern "C" int func_ov031_02217d1c(void* obj);
extern "C" void func_ov031_02217db4(void* s, unsigned int stackSize);

// USA: func_ov031_02216b90
ARM int SetupAndCheck_02216b90(int mode) {
    if (strcmp(data_ov031_02249b54.namePtr, data_ov031_02249bb8) != 0) {
        data_ov031_02249b54.field14 = 1;
    }
    data_ov031_02249b54.fieldC = *(int*)(data_ov031_0224e5e8.base + 0x1000 + 0x20c);
    data_ov031_02249b54.field10 = *(int*)(data_ov031_0224e5e8.base + 0x1000 + 0x210);
    if (func_ov031_02217c00(*(void**)(data_ov031_0224e5e8.base + 0x1000 + 0x314)) != 0) {
        return 4;
    }
    if (mode == 1) {
        func_ov031_0221ae00(&data_ov031_0224e5f4);
    }
    *(int*)(data_ov031_0224e5e8.base + 0x1000 + 0x4) = func_ov031_022173f4(
        *(int*)(data_ov031_0224e5e8.base + 0x1000 + 0x314),
        data_ov031_0224e5e8.base + 0x1200,
        data_ov031_0224e5e8.base + 0x11cc);
    if (*(int*)(data_ov031_0224e5e8.base + 0x1000 + 0x4) != 0) {
        return 4;
    }
    if (func_ov031_02217d1c(*(void**)(data_ov031_0224e5e8.base + 0x1000 + 0x314)) != 0) {
        return 4;
    }
    unsigned int priority = GetContextPriority(data_02111304.activeContext);
    func_ov031_02217db4(*(void**)(data_ov031_0224e5e8.base + 0x1000 + 0x314), priority - 1);
    return 0;
}
