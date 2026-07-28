#include <globaldefs.h>
#include "std_library_functions.h"

int GetGlobalField0x1c020421a0();

extern "C" void func_ov000_0217c638(void* obj, int a, int b);
extern "C" void func_ov000_02177f74(void* obj, void* buf);
extern "C" void func_0205d304(void* s, void* buf, int a, int b, int c, int d, int e, int f);

struct InStruct_02177e50 {
    char pad[0x44];
    int x;
    int y;
};

// USA: func_ov000_02177e50
extern "C" ARM void func_ov000_02177e50(void* objRaw, struct InStruct_02177e50* in, int arg2, int arg3) {
    char* obj = (char*)objRaw;
    if (in == 0) {
        return;
    }
    int x = in->x;
    int y = in->y;
    func_ov000_0217c638(obj, arg2, arg3);
    char* s = obj + 0x188;
    *(short*)(s + 0xa0) = 0xb;
    *(short*)(s + 0xa2) = 9;
    *(short*)(s + 0xa4) = (x >> 3) + 9;
    *(short*)(s + 0xa6) = y >> 3;
    *(short*)(s + 0xa8) = 0xc;
    *(short*)(s + 0xaa) = 8;
    *(short*)(s + 0xac) = 0xa;
    *(short*)(s + 0xae) = 0xd;
    *(unsigned char*)(s + 0xb1) = 6;
    void* buf;
    int savedField58 = *(int*)(s + 0x58);
    buf = *(void**)((char*)GetGlobalField0x1c020421a0() + 0x5c);
    memset(buf, 0, 0x960);
    func_ov000_02177f74(obj, buf);
    int flag = (savedField58 > 1) ? 1 : 0;
    func_0205d304(s, buf, 0, 0, flag, 1, 0, 0);
}
