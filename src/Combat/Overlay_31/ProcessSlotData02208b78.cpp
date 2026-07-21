#include <globaldefs.h>
#include "System/Memory.h"

int IsValueEqual3_02208aa0(int v);
extern "C" void func_ov031_02207a10(void* obj);
extern "C" int func_ov031_02208a40(void* addr, int v1, int v2);

// USA: func_ov031_02208b78  (semantic: ProcessSlotData02208b78)
extern "C" ARM int func_ov031_02208b78(void* obj, unsigned char* data) {
    (void)*(volatile unsigned char*)(data + 1);
    int eq = IsValueEqual3_02208aa0(data[0]);
    if (!eq) return eq;

    VectorizedInvertedMemcpy(data + 2, (char*)obj + 0x34, 0x20);
    unsigned char b = data[0x22];
    unsigned char* p = data + 0x23;
    if (b != 0x20) {
        *(unsigned char*)((char*)obj + 0x30) = 0;
    } else {
        VectorizedInvertedMemcpy(p, (char*)obj + 0x74, 0x20);
        func_ov031_02207a10(obj);
    }

    unsigned char* addr = p + b;
    int lo = addr[0];
    int hi = addr[1];
    addr += 2;
    int combined = hi + (lo << 8);
    int v1 = combined / 2;

    unsigned short ret = (unsigned short)func_ov031_02208a40(addr, v1, 2);
    *(unsigned short*)((char*)obj + 0x32) = ret;
    if (ret != 0) {
        ret = 1;
        *(unsigned char*)((char*)obj + 0x455) = 1;
    }
    return ret;
}
