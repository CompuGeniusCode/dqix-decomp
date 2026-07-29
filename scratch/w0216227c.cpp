#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
void ClearBitsInWord(unsigned int* obj, unsigned int mask);
extern "C" void func_ov028_021d9714(void);
void PopStack1AndTrigger(int flag);

// USA: func_ov001_0216227c
ARM int Something_0216227c(void) {
    ClearBitsInWord((unsigned int*)func_ov017_0218b5b0(), 0x1000);
    func_ov028_021d9714();
    PopStack1AndTrigger(1);
    return 1;
}
