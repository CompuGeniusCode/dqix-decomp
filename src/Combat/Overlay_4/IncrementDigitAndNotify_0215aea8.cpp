#include <globaldefs.h>

struct Struct021707d8_0215aea8 { char pad[8]; char* ptr; };
extern Struct021707d8_0215aea8 data_ov004_021707d8;

extern "C" void* func_ov004_02156fa0(void* obj, int key);
extern "C" void func_ov023_021fb27c(void* node, int val);

// USA: func_ov004_0215aea8  (semantic: IncrementDigitAndNotify_0215aea8)
extern "C" ARM int func_ov004_0215aea8(void* obj) {
    char* ptr = data_ov004_021707d8.ptr;
    signed char* arr = (signed char*)(ptr + 0x3f);
    unsigned char idx = *(unsigned char*)(ptr + 0x3e);
    signed char v = arr[idx];
    v = v + 1;
    arr[idx] = v;
    v = arr[idx];
    if (v >= 10) {
        v = 0;
        arr[idx] = v;
    }
    void* node = func_ov004_02156fa0(obj, *(unsigned char*)(data_ov004_021707d8.ptr + 0x3e) + 0x2d);
    if (node) {
        signed char d = arr[idx];
        func_ov023_021fb27c(node, (unsigned short)(d + 0x1a));
    }
    return 0;
}
