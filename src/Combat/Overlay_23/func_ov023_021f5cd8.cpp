#include <globaldefs.h>
#include "std_library_functions.h"

unsigned long long ComputeModHash_021f6324(int count, unsigned char* ptr);
extern "C" void func_ov031_022118a8(void* ctx, unsigned char* key, int keylen);
extern "C" void Rc4Crypt_02211938(unsigned char* ctx, const unsigned char* in, int len, unsigned char* out);
extern unsigned char data_ov023_021fe3c8[];

// USA: func_ov023_021f5cd8
extern "C" ARM int func_ov023_021f5cd8(unsigned char* buf, int len, unsigned char* out) {
    if (ComputeModHash_021f6324(len, buf) != 0) {
        return 0;
    }
    char ctx[0x104];
    char* key = (char*)data_ov023_021fe3c8;
    int keylen = strlen(key);
    func_ov031_022118a8(ctx, (unsigned char*)key, keylen);
    Rc4Crypt_02211938((unsigned char*)ctx, buf, len - 4, out);
    memcpy(buf, out, len - 4);
    return 1;
}
