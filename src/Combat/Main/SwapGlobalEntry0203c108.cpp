#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_0200f374(void* buf, int n);
extern "C" void func_0203c5a8(void* ptr, void* buf, short* fieldAddr);
extern void* data_02105244;

void ReleaseGlobalEntry0203c198(char* obj);

struct RefArray0xc6b8;
void IncrementEntryCount0x24(struct RefArray0xc6b8* obj, short index);

struct RefArray0xc6fc;
void DecrementEntryCount0x24(struct RefArray0xc6fc* obj, short index);

struct Obj0203c108 {
    char pad[0x14];
    short idx;
};

// USA: func_0203c108
ARM void SwapGlobalEntry0203c108(struct Obj0203c108* obj, char* fmt) {
    if (data_02105244 != NULL && fmt != NULL && *fmt != 0) {
        char buf[0x100];
        func_0200f374(buf, 0x100);
        sprintf(buf, fmt);
        short oldIdx = obj->idx;
        IncrementEntryCount0x24((struct RefArray0xc6b8*)data_02105244, oldIdx);
        ReleaseGlobalEntry0203c198((char*)obj);
        func_0203c5a8(data_02105244, buf, &obj->idx);
        DecrementEntryCount0x24((struct RefArray0xc6fc*)data_02105244, oldIdx);
    }
}
