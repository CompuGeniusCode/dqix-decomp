#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void* self);
extern "C" void func_0203b19c(void* handle, int a, int b);
int CheckField0x20Positive(int* obj);
extern "C" void func_ov023_021e7340(void* arg);
extern "C" void func_ov023_021e6594(void* self);
void* GetDataPtr02114e04_020d6c00(void);
struct FlagWord020466f4;
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);
void ClearBitsInWord(unsigned int* obj, unsigned int mask);

// USA: func_ov012_02189264  (semantic: ProcessBattleTag02189264)
extern "C" ARM void func_ov012_02189264(char* self) {
    void* handle = func_ov017_0218b5b0(self);
    unsigned char state = *(unsigned char*)(self + 0x1370);
    if (state == 0) {
        func_0203b19c(handle, ~0xf, 0xf);
        (*(unsigned char*)(self + 0x1370))++;
        return;
    }
    if (state != 1) return;
    if (CheckField0x20Positive((int*)handle) != 0) return;

    *(int*)(self + 0x131c) = 0;
    *(int*)(self + 0x1324) = 0;
    func_ov023_021e7340(self + 0xd28);
    func_ov023_021e6594(self);
    ClearFlags020466f4((struct FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0xf);
    ClearBitsInWord((unsigned int*)handle, 0x10);
    *(int*)(self + 0x139c) = 1;
    *(unsigned char*)(self + 0x1370) = 0;
}
