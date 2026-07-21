#include <globaldefs.h>
#include "System/Memory.h"
#include "std_library_functions.h"

void InitSha1State_0220b8a0(unsigned int* ctx);
extern "C" void func_ov031_0220b8f4(void* ctx, const void* data, unsigned int len);
void FinalizeSha1Digest_0220b9ac(void* ctx, void* out);
void InitMd5Ctx_0220afe0(void* ctx);
extern "C" void func_ov031_0220b028(void* ctx, const void* data, unsigned int len);
void FinalizeMd5_0220b0e0(void* ctx, void* out);

// USA: func_ov031_02208e54  (semantic: HashPassword02208e54)
extern "C" ARM void func_ov031_02208e54(void* out, const char* password, void* ctx) {
    char* base = (char*)ctx;
    InitSha1State_0220b8a0((unsigned int*)(base + 0x348));
    unsigned int len = strlen(password);
    func_ov031_0220b8f4(base + 0x348, password, len);
    func_ov031_0220b8f4(base + 0x348, ctx, 0x30);
    func_ov031_0220b8f4(base + 0x348, base + 0x34, 0x40);
    unsigned char digest[0x14];
    FinalizeSha1Digest_0220b9ac(base + 0x348, digest);

    InitMd5Ctx_0220afe0(base + 0x3fc);
    func_ov031_0220b028(base + 0x3fc, ctx, 0x30);
    func_ov031_0220b028(base + 0x3fc, digest, 0x14);
    FinalizeMd5_0220b0e0(base + 0x3fc, out);
}
