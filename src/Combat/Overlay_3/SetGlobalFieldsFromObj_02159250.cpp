#include <globaldefs.h>

int GetGlobalField0x1c020421a0();
extern "C" void func_0204500c(void*, int, int, int);

// USA: func_ov003_02159250  (semantic: SetGlobalFieldsFromObj_02159250)
extern "C" ARM void func_ov003_02159250(char* obj, int flag) {
    if (flag == 0) return;
    int g = GetGlobalField0x1c020421a0();
    func_0204500c((void*)g, flag, 0, 0xe3);
    *(unsigned char*)(g + 0x19b2) = (unsigned char)obj[0x5b2];
    *(int*)(g + 0x99c) = (unsigned char)obj[0x5b1];
}
