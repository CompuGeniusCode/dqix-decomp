#include <globaldefs.h>

extern "C" int func_02092bcc(void* p, int val);
extern "C" int func_02092b34(void* p);
extern "C" void func_ov000_02176e3c(void* obj, int zero, int val, int arg1, int arg2, int one);
extern "C" void func_ov000_0217c638(void* obj, int arg1, int arg2);

// USA: func_ov000_0217de64
extern "C" ARM void func_ov000_0217de64(char* obj, int arg1, int arg2) {
    unsigned short flags = *(unsigned short*)(obj + 0x1d72);
    *(unsigned short*)(obj + 0x1d72) = flags & ~0x100;
    int r = func_02092bcc(obj + 0x7c, *(int*)(obj + 0x94c));
    if (r == 0) {
        return;
    }
    func_02092b34(obj + 0x7c);
    signed char idx1 = *(volatile signed char*)(obj + 0x1d68);
    *(unsigned char*)(obj + idx1 + 0x1d60) = 0;
    *(signed char*)(obj + 0x1d68) = *(volatile signed char*)(obj + 0x1d68) - 1;
    func_ov000_02176e3c(obj, 0, *(signed char*)(obj + *(volatile signed char*)(obj + 0x1d68) + 0x1d60), arg1, arg2, 0);
    func_ov000_0217c638(obj, arg1, arg2);
}
