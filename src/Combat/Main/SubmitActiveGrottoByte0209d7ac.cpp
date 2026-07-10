#include <globaldefs.h>

extern "C" void* func_02012fe4();
extern "C" void func_ov017_021d6134(void*, int);

class ActiveGrottoClass {
public:
    unsigned char* BlankFunction() const;
};

// USA: func_0209d7ac
ARM int SubmitActiveGrottoByte0209d7ac(void* arg) {
    ActiveGrottoClass* grotto = (ActiveGrottoClass*)((char*)func_02012fe4() + 0x23ec);
    if (grotto == NULL) return 0;
    unsigned char* p = grotto->BlankFunction();
    if (p == NULL) return 0;
    func_ov017_021d6134(arg, p[1]);
    return 1;
}
