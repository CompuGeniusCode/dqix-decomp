#include <globaldefs.h>

void ClearFirstThreeWords(unsigned int*);
extern "C" void func_0200f3a4(void*);

// USA: func_02012200
ARM char* ClearSubMemberAndReset(char* obj) {
    ClearFirstThreeWords((unsigned int*)(obj + 0x468));
    func_0200f3a4(obj);
    return obj;
}
