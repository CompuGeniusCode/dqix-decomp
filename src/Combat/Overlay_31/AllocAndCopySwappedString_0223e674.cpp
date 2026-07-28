#include <globaldefs.h>

extern "C" int func_ov031_0223fb48(const char* s);
void CopyBytesSwapped_0223fb74(void* dst, const void* src, unsigned int length);

struct AllocEntry0223e674 { unsigned char pad[0xc]; void* (*allocFn)(unsigned int, unsigned int); };
extern AllocEntry0223e674 data_ov031_02290da0;

// USA: func_ov031_0223e674  (semantic: AllocAndCopySwappedString_0223e674)
extern "C" ARM void* func_ov031_0223e674(const char* a0) {
    int len = func_ov031_0223fb48(a0);
    void* p = data_ov031_02290da0.allocFn(len + 1, 4);
    if (p != 0) {
        CopyBytesSwapped_0223fb74(p, a0, len);
        ((char*)p)[len] = 0;
    }
    return p;
}
