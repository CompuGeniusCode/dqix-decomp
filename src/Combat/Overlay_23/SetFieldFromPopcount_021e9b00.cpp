#include <globaldefs.h>

extern "C" void* func_0205ec34(void* obj);
unsigned short BuildBitmask0206e384(unsigned char* obj);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021e9b00
ARM int SetFieldFromPopcount_021e9b00(void* obj) {
    void* sub = func_0205ec34(obj);
    unsigned int combined = 0xffff | (BuildBitmask0206e384((unsigned char*)sub) << 16);
    int count = 0;
    while (combined != 0) {
        count += combined & 1;
        combined >>= 1;
    }
    func_ov017_021d6134(obj, count);
    return 1;
}
