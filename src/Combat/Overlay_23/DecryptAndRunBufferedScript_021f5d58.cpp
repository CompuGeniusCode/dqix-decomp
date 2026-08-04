#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

unsigned long long ComputeModHash_021f6324(int count, unsigned char* ptr);
extern "C" void func_ov031_022118a8(void* ctx, unsigned char* key, int keylen);
extern "C" void Rc4Crypt_02211938(unsigned char* ctx, const unsigned char* in, int len, unsigned char* out);
extern unsigned char data_ov023_021fe3c8[];

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);
struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);
struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);
extern "C" void func_0203066c(struct ResetStruct*, int*);
extern int data_ov023_021fe34c;

struct Data021fff08_021f5d58 { char pad[0xc]; void* fieldC; void* field10; };
extern struct Data021fff08_021f5d58 data_ov023_021fff08;

// USA: func_ov023_021f5d58  (semantic: DecryptAndRunBufferedScript_021f5d58)
extern "C" ARM int func_ov023_021f5d58(unsigned char* buf, int len, unsigned char* out) {
    if (ComputeModHash_021f6324(len, buf) != 0) {
        return 0;
    }
    char local[0x430];
    char ctx[0x104];
    char* key = (char*)data_ov023_021fe3c8;
    int keylen = strlen(key);
    func_ov031_022118a8(ctx, (unsigned char*)key, keylen);
    Rc4Crypt_02211938((unsigned char*)ctx, buf, len - 4, out);
    char* bs = (char*)GetBattleStruct();
    data_ov023_021fff08.fieldC = bs + 0x5e6c;
    data_ov023_021fff08.field10 = 0;
    ResetFieldsReturnTrue((struct ResetStruct*)local);
    func_0203066c((struct ResetStruct*)local, &data_ov023_021fe34c);
    InitBufferReader((struct StreamState*)local, (struct StreamHeader*)out, len - 4);
    RunLoopIfValid02030774((struct Struct02030774*)local);
    if (data_ov023_021fff08.field10 == 0) {
        return 0;
    }
    memset(bs + 0x5f80, 0, 0x200);
    char* str = (char*)data_ov023_021fff08.field10;
    memcpy(bs + 0x5f80, str, strlen(str));
    return 1;
}
