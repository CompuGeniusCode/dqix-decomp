#include <globaldefs.h>

void EnableInstructionTcm(void);
void EnableDataTcm(void);

struct ClearFields0And8And0x20Struct;
void ClearFields0And8And0x20(struct ClearFields0And8And0x20Struct* p);

extern "C" void func_01ff8810(void*);
extern "C" void func_020c93d0(void*, int, int, void*, void*);
extern "C" void func_01ff96c0(void*);

extern unsigned int data_0214e5e4[];
extern int data_0214e5bc;

// USA: func_020dc034
ARM void InitStreamAndRegisterHandler0xC0(void) {
    EnableInstructionTcm();
    EnableDataTcm();
    func_01ff8810(data_0214e5e4);
    ClearFields0And8And0x20((struct ClearFields0And8And0x20Struct*)&data_0214e5bc);
    func_020c93d0(&data_0214e5bc, 0xc0, 0xf, (void*)func_01ff96c0, data_0214e5e4);
}
