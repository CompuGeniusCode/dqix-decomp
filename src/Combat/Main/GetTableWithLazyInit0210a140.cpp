#include <globaldefs.h>

extern "C" void func_020b3994(void);

struct InitGuard0210a010 { unsigned char pad[0xfc]; unsigned int flags; };
extern InitGuard0210a010 data_0210a010;
extern char data_0210a140;

// USA: func_020b39ec
ARM void* GetTableWithLazyInit0210a140(void) {
    if (!(data_0210a010.flags & 0x80)) {
        func_020b3994();
        data_0210a010.flags |= 0x80;
    }
    return &data_0210a140;
}
