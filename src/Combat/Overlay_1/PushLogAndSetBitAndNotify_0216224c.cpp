#include <globaldefs.h>

void PushInputLogB(int id);
extern "C" char* func_ov017_0218b5b0(void);
void SetBitsInWord(unsigned int* obj, unsigned int mask);
extern int data_ov001_021658b8;
extern "C" void func_ov028_021d96bc(int);

// USA: func_ov001_0216224c
ARM int PushLogAndSetBitAndNotify_0216224c(void) {
    PushInputLogB(5);
    SetBitsInWord((unsigned int*)func_ov017_0218b5b0(), 0x1000);
    func_ov028_021d96bc(data_ov001_021658b8);
    return 1;
}
